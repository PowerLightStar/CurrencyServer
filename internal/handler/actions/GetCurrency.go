package actions

import (
	base "GolangCurrencyMS/internal/handler"
	"GolangCurrencyMS/internal/payload"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
)

type GetCurrencyController struct {
}

func NewGetCurrencyController() base.Controller {
	return &GetCurrencyController{}
}

func (c *GetCurrencyController) Handler() gin.HandlerFunc {
	return func(ctx *gin.Context) {
		currencyName := ctx.Param("item")

		var strings []string
		if currencyName == "all" {
			strings = GetAllCurrencyId()
			// log.Printf("-----------%+v\n", strings)
		} else {
			strings = append(strings, currencyName)
		}

		currencyList := make([]payload.DataResponse, len(strings))
		for i, item := range strings {

			if i > 5 {
				break
			}

			sourceUrl := "https://api.hitbtc.com/api/3/public"
			newTicker := GetDataFromAPI(sourceUrl+"/ticker/"+item, payload.TickerRequest{})
			newSymbol := GetDataFromAPI(sourceUrl+"/symbol/"+item, payload.SymbolRequest{})
			fullNameForSymbol := GetDataFromAPI(sourceUrl+"/currency/"+newSymbol.BaseCurrency, payload.CurrencyRequest{})

			// log.Printf("%s____%s____%s\n", newTicker, newSymbol, fullNameForSymbol)

			newCurrency := payload.DataResponse{
				Id:          newSymbol.BaseCurrency,
				FullName:    fullNameForSymbol.FullName,
				Ask:         newTicker.Ask,
				Bid:         newTicker.Bid,
				Last:        newTicker.Last,
				Open:        newTicker.Open,
				Low:         newTicker.Low,
				High:        newTicker.High,
				FeeCurrency: newSymbol.FeeCurrency,
			}

			currencyList[i] = newCurrency
		}
		log.Printf("%+v\n", currencyList)

		if currencyName == "all" {
			ctx.JSON(http.StatusOK, gin.H{"currencies": currencyList})
		} else {
			ctx.JSONP(http.StatusOK, currencyList[0])
		}
	}
}

func (c *GetCurrencyController) Route() string {
	return "/currency/:item"
}

func (c *GetCurrencyController) Method() string {
	return http.MethodGet
}

func GetDataFromAPI[Req payload.TickerRequest | payload.SymbolRequest | payload.CurrencyRequest](url string, format Req) Req {
	resp, err := http.Get(url)
	if err != nil {
		log.Fatalln(err)
	}
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)

	json.Unmarshal([]byte(body), &format)
	fmt.Printf("%+v\n", format)

	return format
}

func GetAllCurrencyId() []string {
	resp, err := http.Get("https://api.hitbtc.com/api/3/public/symbol")
	if err != nil {
		log.Fatalln(err)
	}
	defer resp.Body.Close()

	body, err := ioutil.ReadAll(resp.Body)

	c := make(map[string]json.RawMessage)

	e := json.Unmarshal([]byte(body), &c)
	if e != nil {
		panic(e)
	}

	IdList := make([]string, len(c))
	i := 0
	for s, _ := range c {
		IdList[i] = s
		i++
	}

	return IdList
}

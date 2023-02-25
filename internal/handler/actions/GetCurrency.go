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
		fmt.Printf("%s___currencyName\n", currencyName)

		sourceUrl := "https://api.hitbtc.com/api/3/public"
		newTicker := GetDataFromAPI(sourceUrl+"/ticker/"+currencyName, payload.TickerRequest{})
		newSymbol := GetDataFromAPI(sourceUrl+"/symbol/"+currencyName, payload.CurrencyRequest{})
		log.Printf("%s____%s\n", newTicker, newSymbol)

		newCurrency := payload.DataResponse{
			Id:          newSymbol.BaseCurrency,
			FullName:    currencyName,
			Ask:         newTicker.Ask,
			Bid:         newTicker.Bid,
			Last:        newTicker.Last,
			Open:        newTicker.Open,
			Low:         newTicker.Low,
			High:        newTicker.High,
			FeeCurrency: newSymbol.FeeCurrency,
		}

		ctx.JSON(http.StatusOK, gin.H{"status": true, "payload": newCurrency})
	}
}

func (c *GetCurrencyController) Route() string {
	return "/currency/:item"
}

func (c *GetCurrencyController) Method() string {
	return http.MethodGet
}

func GetDataFromAPI[Req payload.TickerRequest | payload.CurrencyRequest](url string, format Req) Req {
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

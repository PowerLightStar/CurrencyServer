package actions

import (
	base "GolangCurrencyMS/internal/handler"
	"fmt"
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
		currencyItem := ctx.Param("item")

		fmt.Printf("%s___affefeefef\n", currencyItem)
		ctx.JSON(http.StatusOK, gin.H{"result": "OK"})
	}
}

func (c *GetCurrencyController) Route() string {
	return "/currency/:item"
}

func (c *GetCurrencyController) Method() string {
	return http.MethodGet
}

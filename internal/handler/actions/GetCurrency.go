package actions

import (
	base "GolangCurrencyMS/internal/handler"
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

		ctx.JSON(http.StatusOK, gin.H{"result": "OK"})
	}
}

func (c *GetCurrencyController) Route() string {
	return "/currency/all"
}

func (c *GetCurrencyController) Method() string {
	return http.MethodGet
}

package actions

import (
	base "GolangCurrencyMS/internal/handler"
	"net/http"

	"github.com/gin-gonic/gin"
)

type GetDashboardController struct {
}

func NewGetDashboard() base.Controller {
	return &GetDashboardController{}
}

func (c *GetDashboardController) Handler() gin.HandlerFunc {
	return func(ctx *gin.Context) {
		ctx.JSON(http.StatusOK, gin.H{"status": true})
	}
}

func (c *GetDashboardController) Route() string {
	return "/"
}

func (c *GetDashboardController) Method() string {
	return http.MethodGet
}

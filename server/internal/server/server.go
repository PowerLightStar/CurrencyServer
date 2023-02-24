package server

import (
	"GolangCurrencyMS/server/config"
	"GolangCurrencyMS/server/internal/handler"
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
)

type Server interface {
	Run() error
}

type server struct {
	controllers []handler.Controller
	config      *config.Config
}

func NewServer(cfg *config.Config, ctrls ...handler.Controller) Server {
	return &server{
		controllers: ctrls,
		config:      cfg,
	}
}

func (s *server) Run() error {
	// router, err := s.buildRouter()
	// if err != nil {
	// 	return err
	// }

	// srv := &http.Server{
	// 	Addr:    fmt.Sprintf(":%d", s.config.App.Port),
	// 	Handler: router,
	// }

	// startupFailed := make(chan interface{}, 1)
	// defer close(startupFailed)

	// go func() {

	// }
	return nil
}

func (s *server) buildRouter() (*gin.Engine, error) {
	router := gin.Default()

	for _, ctrl := range s.controllers {
		method := ctrl.Method()

		switch method {
		case http.MethodGet:
			router.GET(ctrl.Route(), ctrl.Handler())

		default:
			return nil, fmt.Errorf("Cannot create HTTP handler of method %s", method)
		}
	}
	return router, nil
}

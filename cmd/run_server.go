package main

import (
	"GolangCurrencyMS/config"
	act_handler "GolangCurrencyMS/internal/handler/actions"
	"GolangCurrencyMS/internal/server"
	"fmt"
	"log"
)

func main() {
	appConfiguration, err := config.LoadConfig()
	if err != nil {
		fmt.Println("Oh no!")
		panic(err)
	}

	server := server.NewServer(
		appConfiguration,
		act_handler.NewGetCurrencyController(),
	)

	log.Printf("runserver  %d\n", appConfiguration.App.Port)

	if err = server.Run(); err != nil {
		panic(err)
	}
}

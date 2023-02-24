package main

import "GolangCurrencyMS/server/config"

func main() {
	appConfiguration, err := config.LoadConfig()

	if err != nil {
		panic(err)
	}

	// server := server
}

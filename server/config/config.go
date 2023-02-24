package config

import (
	"fmt"
	"os"
	"strings"

	"github.com/spf13/viper"
)

type Config struct {
	App struct {
		Port int `mapstructure:"port"`
	} `mapstructure:"app"`
}

func LoadConfig() (*Config, error) {
	conf := viper.New()

	config_name := fmt.Sprintf("%s.yaml", getWebEnv())
	fmt.Println(config_name)
	conf.SetConfigFile(config_name)
	conf.SetConfigType("yaml")
	conf.SetEnvKeyReplacer(strings.NewReplacer(".", "-"))
	conf.AutomaticEnv()

	c := &Config{}
	err := conf.Unmarshal(c)

	return c, err
}

const defaultEnv = "currencyMS"

func getWebEnv() string {
	env := os.Getenv("WEB_ENV")
	if env != "" {
		return env
	}

	return defaultEnv
}

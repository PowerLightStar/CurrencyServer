# GolangCurrencyMS
Crypto Server: Micro service for currency

Pls make use of the fre API from https://api.hitbtc.com/ to complete this challenge

Create a micro-service with the following endpoint.

### GET /currency/{symbol}

Returns the real-time crypto prices of the given currency symbol.

Sample Response:
```sh
{
  "id": "ETH",
  "fullName": "Ethereum",
  "ask": 0.054464,
  "bid": 0.054463,
  "last": 0.054463,
  "open": 0.057133,
  "low": 0.553615,
  "high": 0.057559,
  "feeCurrency": "BTC"
}
```
### GET /currency/all

Returns the real-time crypto prices of all the supported currencies.

Sample Response:
```sh
{
  [
    {
      "id": "ETH",
      "fullName": "Ethereum",
      "ask": 0.054464,
      "bid": 0.054463,
      "last": 0.054463,
      "open": 0.057133,
      "low": 0.553615,
      "high": 0.057559,
      "feeCurrency": "BTC"
    },
    {
      "id": "BTC",
      "fullName": "Bitcoin",
      "ask": 7906.72,
      "bid": 7906.28,
      "last": 7906.48,
      "open": 7952.3,
      "low": 7561.51,
      "high": 8107.96,
      "feeCurrency": "USD"
    }
  ]
}
```


# Sistema de Controle de Nível de Água

//descobri um método ultra eficiente para medição, chamado 'ladder resistor' que pode potencializar significativamente esse projeto 

Este projeto consiste em um sistema automatizado para controlar o nível de água, utilizando um sensor de nível e uma válvula solenoide. O código é escrito em C++ para plataformas como Arduino.

## Funcionalidades

- **Detecção de Nível de Água**: Utiliza um sensor de nível para monitorar constantemente o nível de água.
- **Controle Automático da Válvula**: Abre ou fecha a válvula solenoide com base no nível de água detectado.

## Componentes

- Sensor de nível de água
- Válvula solenoide
- Arduino (ou compatível)

## Configuração dos Pinos

- `pinSensorNivel`: Pino conectado ao sensor de nível de água. (Definido como 2)
- `pinValvula`: Pino conectado à válvula solenoide. (Definido como 3)

## Instalação

1. Conecte o sensor de nível de água ao pino definido em `pinSensorNivel`.
2. Conecte a válvula solenoide ao pino definido em `pinValvula`.
3. Carregue o código no seu Arduino.

## Código

```cpp
// Definições dos pinos
const int pinSensorNivel = 2;  // Pino conectado ao sensor de nível de água
const int pinValvula = 3;      // Pino conectado à válvula solenoide

void setup() {
  pinMode(pinSensorNivel, INPUT); // Define o pino do sensor como entrada
  pinMode(pinValvula, OUTPUT);    // Define o pino da válvula como saída
  digitalWrite(pinValvula, HIGH); // Inicia com a válvula fechada
}

void loop() {
  int nivelAgua = digitalRead(pinSensorNivel); // Lê o estado do sensor de nível de água

  if (nivelAgua == LOW) {
    digitalWrite(pinValvula, HIGH); // Fecha a válvula
  } else {
    digitalWrite(pinValvula, LOW); // Abre a válvula
  }
  
  delay(2000); // Um pequeno atraso para evitar leituras ruidosas
}
```

## Contribuições

Contribuições são sempre bem-vindas! Se você tem alguma sugestão de melhoria, sinta-se à vontade para abrir um _issue_ ou enviar um _pull request_.

# RFIDAccessControlSystem

## Introdução
Este projeto é um sistema de controle de acesso utilizando RFID. O objetivo é ler o UID de cartões RFID e verificar se estão autorizados para conceder ou negar acesso.

## Lista de Materiais Necessários
- Arduino Uno
- Módulo RFID-RC522
- LEDs (2 unidades)
- Resistores (2 unidades)
- Jumpers
- Protoboard

## Propósito do Projeto
O projeto foi criado para fornecer uma solução simples e eficaz de controle de acesso utilizando RFID. Pode ser utilizado em diversas aplicações, como controle de entrada em ambientes restritos, sistemas de segurança e automação residencial.

## Prós e Contras
### Prós
- Fácil de implementar
- Baixo custo
- Compatível com diversos cartões RFID

### Contras
- Segurança limitada (UIDs podem ser clonados)
- Alcance limitado do leitor RFID

## Orientações Gerais
### Configuração
1. Conecte o módulo RFID-RC522 ao Arduino conforme o esquema de ligação:
   - SDA -> Pin 10
   - SCK -> Pin 13
   - MOSI -> Pin 11
   - MISO -> Pin 12
   - IRQ -> Não conectado
   - GND -> GND
   - RST -> Pin 9
   - 3.3V -> 3.3V

2. Conecte os LEDs aos pinos 7 (Acesso Concedido) e 6 (Acesso Negado) com resistores em série.

### Instalação
1. Baixe e instale a biblioteca `MFRC522` através do Gerenciador de Bibliotecas do Arduino IDE.
2. Carregue o código fornecido no Arduino.

### Uso
1. Abra o Monitor Serial na Arduino IDE.
2. Aproxime um cartão RFID ao leitor.
3. O sistema irá verificar o UID do cartão e acender o LED correspondente (Acesso Concedido ou Acesso Negado).

### Solução de Problemas
- Verifique as conexões dos pinos se o leitor RFID não estiver funcionando.
- Certifique-se de que a biblioteca `MFRC522` está corretamente instalada.

## Licença
Este projeto é open-source e pode ser utilizado livremente, sujeito aos termos da licença MIT.
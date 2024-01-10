# HomeAlertSync

## Introdução
O HomeAlertSync é um projeto Arduino que notifica o usuário via smartphone quando um alarme residencial é disparado. Utiliza a plataforma Blynk para efetuar a comunicação.

## Lista de Materiais Necessários
- Placa ESP8266 (NodeMCU ou similar)
- Sensor de alarme (Interruptor de Reed, Sensor PIR, etc.)
- Cabos de conexão
- Smartphone com o aplicativo Blynk instalado

## Propósito do Projeto
Este projeto foi criado para oferecer uma solução simples e eficiente para monitorar a segurança da sua casa. É ideal para pessoas que querem uma maneira acessível de se manterem informadas sobre a segurança da sua residência.

## Prós e Contras
**Prós:**
- Fácil de configurar e usar.
- Notificação imediata no seu celular.

**Contras:**
- Depende da conexão com a Internet.
- Requer configuração inicial no aplicativo Blynk.

## Orientações Gerais
### Configuração
1. Monte o circuito conectando o sensor ao ESP8266.
2. Carregue o código fornecido no ESP8266.
3. Configure o Blynk com o token gerado e conecte o dispositivo.

### Operação
Uma vez configurado, o sistema enviará uma notificação para o seu celular sempre que o estado do sensor de alarme mudar para indicar uma violação.

### Solução de Problemas
- Certifique-se de que a placa ESP8266 esteja corretamente conectada à sua rede Wi-Fi.
- Verifique se o token do Blynk está correto.

## Licença
Este projeto é distribuído sob a licença MIT. Consulte o arquivo LICENSE para mais detalhes.

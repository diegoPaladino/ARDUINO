# FireAlertDrawer

## Introdução
O FireAlertDrawer é um projeto Arduino desenvolvido para detectar sinais de incêndio em gavetas onde gadgets são carregados. O sistema aciona um alarme sonoro de alta frequência quando detecta fumaça ou calor excessivo, alertando sobre o perigo iminente.

## Lista de Materiais Necessários
- Arduino (Qualquer modelo compatível com pinos analógicos e digitais)
- Sensor de som (como o módulo de microfone de alta sensibilidade)
- Buzzer (compatível com Arduino)
- Cabos de conexão

## Propósito do Projeto
Este projeto visa prevenir incêndios em locais onde múltiplos dispositivos eletrônicos são carregados simultaneamente, como gavetas ou caixas de armazenamento. É ideal para locais residenciais ou escritórios onde o carregamento de gadgets é comum.

## Prós e Contras
### Prós:
- Alerta precoce de possíveis incêndios.
- Fácil de instalar e configurar.

### Contras:
- Depende da sensibilidade e calibração do sensor de som.
- Pode disparar falsos alarmes se não ajustado corretamente.

## Orientações Gerais
1. Conecte o sensor de som e o buzzer aos pinos especificados no Arduino.
2. Carregue o código `FireAlertDrawer.ino` no Arduino.
3. Coloque o Arduino dentro da gaveta de carregamento.
4. Ajuste o `SOUND_THRESHOLD` no código conforme a sensibilidade desejada.
5. Teste o sistema para garantir a funcionalidade.

## Licença
Este projeto está disponível para uso e modificação sob a Licença MIT.

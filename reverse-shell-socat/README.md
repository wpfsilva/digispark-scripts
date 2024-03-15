Descrição do Programa: Automação de Backdoor com Arduino e PowerShell

Este programa tem como objetivo automatizar a execução de um ataque de backdoor em um sistema alvo. Consiste em dois arquivos: um script PowerShell (payload.ps1) e um código Arduino (sketch.ino).

Como Configurar:

Definir o IP do Atacante: No script PowerShell (payload.ps1), substitua "IP_DO_ATACANTE" pelo endereço IP do servidor controlado pelo atacante.

Carregar o Script PowerShell no Servidor: Faça o upload do arquivo payload.ps1 para um servidor web acessível ao sistema alvo. Certifique-se de que o Socat esteja disponível para download no mesmo local.

Configurar o Código Arduino: No código Arduino (sketch.ino), substitua "IP_DO_ATACANTE" pela mesma URL usada no script PowerShell.

Carregar o Código Arduino no Dispositivo: Carregue o código Arduino em um dispositivo compatível, como o DigiSpark, utilizando a IDE do Arduino.

Configurar um servidor (ex: netcat) para ouvir na porta especificada.

Nesse exemplo poderiamos usar o : nc -lnvp 4444

Funcionamento:

O script PowerShell (payload.ps1) é responsável por baixar e executar o Socat, uma ferramenta de rede que estabelece conexões bidirecionais entre dois pontos finais. Ele é baixado de uma URL específica fornecida pelo atacante. Após o download, o Socat é descompactado e iniciado em segundo plano, configurado para se conectar ao endereço IP e à porta especificados pelo atacante. Quando a conexão é estabelecida, é iniciado um shell do Windows (cmd.exe), que fica disponível para execução de comandos remotos.

O código Arduino (sketch.ino) configura um dispositivo Arduino, como o DigiSpark, para simular um teclado USB. Quando o dispositivo é conectado ao sistema alvo, ele automaticamente pressiona uma sequência de teclas que abre uma janela do PowerShell em modo oculto, baixa e executa o script payload.ps1 do servidor do atacante. Após o término da execução, a janela do PowerShell é fechada.

Este programa permite que um atacante remoto execute comandos arbitrários no sistema alvo, explorando uma vulnerabilidade na forma como o sistema processa dispositivos USB, utilizando um dispositivo Arduino para automatizar o processo de infecção.

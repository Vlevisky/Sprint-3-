# Sprint-3-
- **Marcos Vinicius Gonçalves Santos** – RM 560062  
- **Matheus Ricardo Parreira da Silva** – RM 560099  
- **Marcos Azuma** – RM 559883  
- **Davi Correa Paiao** – RM 560438  
- **Filip Arnhould Outa** – RM 559294  

## 🧠 Descrição do Projeto

Este projeto propõe um sistema de balança inteligente, capaz de monitorar o peso em tempo real e responder a alterações automaticamente. O sistema é dividido em múltiplas balanças, cada uma associada a um medicamento previamente cadastrado. As balanças enviam seus dados para um sistema central via conexão serial, permitindo requisições e respostas diretas.

A ideia central é facilitar o controle e organização de itens por peso. A cada alteração de peso (por exemplo, retirada de um remédio), a balança envia o dado atualizado e identifica automaticamente qual medicamento está sendo monitorado. O sistema central (Node-RED) pode fazer requisições às balanças a qualquer momento para obter dados atualizados.

## 🎯 Objetivos

- Criar um sistema de pesagem reativo e em tempo real.
- Associar cada balança a um produto fixo (ex: medicamentos).
- Permitir a leitura remota e centralizada das balanças via requests seriais.
- Automatizar o envio de dados em formato JSON para integração com dashboards ou plataformas em nuvem.

## 🔧 Especificações Técnicas

| Componente             | Descrição                              |
|------------------------|----------------------------------------|
| Microcontrolador       | Arduino Uno (simulado no Wokwi)        |
| Sensor                 | HX711 + célula de carga                |
| Comunicação            | Serial (USB) com Node-RED              |
| Plataforma Back-end    | Node-RED (processamento e exibição)    |
| Formato dos dados      | JSON com `nome` fixo e `peso` variável |

## 🧱 Arquitetura em Camadas

### 📦 Camada IoT
- Arduino Uno + sensor HX711
- Detecta alterações de peso

### ☁️ Camada Back-end
- Node-RED
- Envia requisição de leitura para balança
- Recebe JSON com `nome` e `peso`

### 💻 Camada Aplicação
- Painel com Node-RED ou console
- Visualização dos dados por balança
- Registro de atualizações em tempo real

## 🖼️ Diagrama da Solução
![image](https://github.com/user-attachments/assets/55b127fd-5300-47ba-851d-823932aecbc3)

## 📑 Descrição do Diagrama

- As balanças (camada IoT) monitoram os pesos localmente.
- Quando uma alteração significativa ocorre, elas notificam o back-end.
- O back-end (Node-RED) interage com cada balança por meio da interface serial, requisita dados e processa as respostas.
- A aplicação exibe ou registra os dados recebidos, permitindo acompanhamento em tempo real.

🎯 **Objetivo do Projeto**

O programa simula a lógica de comparação de cartas do jogo Super Trunfo, aplicando conceitos fundamentais da linguagem C, como:

Estruturas (struct);

Enumerações (enum);

Funções;

Condições lógicas (if / else).

Cada carta contém atributos como população, área, PIB, pontos turísticos, além de cálculos automáticos de densidade populacional e PIB per capita.

🧩 **Funcionalidades**

✅ Cadastra duas cartas com informações completas;
✅ Calcula automaticamente atributos derivados;
✅ Compara o atributo selecionado e define o vencedor;
✅ Exibe resultado detalhado no terminal;
✅ Fácil de alterar o atributo de comparação.

⚙️ **Tecnologias Utilizadas**
Categoria	Ferramenta
💻 Linguagem	C
🧠 Compilador	GCC
🧩 IDE/Ambiente	GitHub Codespaces / VS Code
🔧 Controle de Versão	Git + GitHub
🚀 Como Executar o Projeto
🌀 1. Clonar o Repositório
git clone https://github.com/elasouza3/cartas_super_trunfo_c.git
cd cartas_super_trunfo_c

⚙️ 2. Compilar o Código
gcc super_trunfo.c -o super_trunfo

▶️ 3. Executar o Programa
./super_trunfo

🧮 **Atributos Comparáveis**

No início do código (super_trunfo.c), altere a macro para escolher o atributo:

#define COMPARE_ATTRIBUTE ATTR_POPULACAO

**Atributo	Macro	Regra de Vitória**
🧍 População	ATTR_POPULACAO	Maior vence
🌎 Área (km²)	ATTR_AREA	Maior vence
💰 PIB	ATTR_PIB	Maior vence
🧮 Densidade populacional	ATTR_DENSIDADE	Menor vence
💵 PIB per capita	ATTR_PIB_PER_CAPITA	Maior vence
🧠 Lógica da Comparação

Para densidade populacional, o menor valor vence.

Para todos os outros atributos, o maior valor vence.

Em caso de igualdade, o resultado é empate.

📘 **A lógica está implementada com if / else if, conforme os requisitos do nível novato do desafio.**

📂 **Estrutura do Projeto**
📁 cartas_super_trunfo_c
├── .vscode/           # Configurações de compilação (tasks.json)
├── .gitignore         # Ignora arquivos executáveis
├── README.md          # Documentação do projeto
├── main.c             # Código principal
└── super_trunfo.c     # Lógica de comparação das cartas

👩‍💻 **Autora**

Elaine Souza
📎 LinkedIn
 • 💻 GitHub

 <p align="center">📚 <em>Projeto acadêmico desenvolvido para fins educacionais e aprendizado da linguagem C.</em></p>

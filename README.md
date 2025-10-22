Tetris Stack — Estruturas de Dados em C
🎮 Sobre o Projeto
O Tetris Stack é um projeto desenvolvido em linguagem C que simula a mecânica de gerenciamento de peças do jogo Tetris, aplicando conceitos fundamentais de estruturas de dados, como filas (queues) e pilhas (stacks).

O objetivo é representar o controle de peças em tempo real — com peças futuras armazenadas em uma fila circular e peças reservadas gerenciadas por uma pilha —, explorando inserções, remoções e trocas de dados entre as estruturas.

🧩 Objetivos de Aprendizado
Aplicar estruturas de dados fila (FIFO) e pilha (LIFO).

Compreender a comunicação entre as duas estruturas.

Utilizar structs, arrays, funções e ponteiros em C.

Criar menus interativos e simular ações típicas do jogo.

Desenvolver raciocínio lógico e modularização de código.

🚀 Níveis de Desenvolvimento
🥉 Nível Novato
Tema: Fila circular de peças futuras

Implementa a estrutura de fila.

Ações: inserir, remover e exibir peças.

Cada peça possui:

nome → tipo da peça ('I', 'O', 'T', 'L')

id → número identificador único

Exemplo de ações:

css
Copiar código
1 - Jogar peça (dequeue)
2 - Inserir nova peça (enqueue)
0 - Sair
🥈 Nível Aventureiro
Tema: Integração da fila com uma pilha de reserva

Adiciona a estrutura de pilha, permitindo reservar e usar peças.

Ações:

css
Copiar código
1 - Jogar peça
2 - Reservar peça
3 - Usar peça reservada
0 - Sair
Mantém a fila sempre cheia, gerando novas peças automaticamente.

Demonstra a manipulação simultânea de fila e pilha.

🥇 Nível Mestre
Tema: Comunicação entre fila e pilha

Implementa operações avançadas como:

Trocar a peça da frente da fila com o topo da pilha.

Realizar trocas múltiplas entre as estruturas.

Reverter a ordem da fila usando a pilha como estrutura auxiliar.

Ações:

css
Copiar código
1 - Jogar peça
2 - Reservar peça
3 - Usar peça reservada
4 - Trocar peça atual
5 - Troca múltipla
0 - Sair
Simula um sistema dinâmico e estratégico de gerenciamento de peças.

🧠 Conceitos Aplicados
Fila circular: gerenciamento FIFO com reaproveitamento de espaço.

Pilha linear: armazenamento LIFO para reversão e reserva.

Structs e arrays: modelagem de dados personalizados.

Funções e modularização: código organizado e reutilizável.

Entrada e saída em C: interação via terminal.

Controle de memória estática: manipulação segura e eficiente.

🛠️ Tecnologias Utilizadas
Linguagem: C (ANSI C)

IDEs sugeridas: VS Code, Code::Blocks ou Replit

Sistema de controle de versão: Git / GitHub


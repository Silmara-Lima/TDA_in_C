# Técnicas de Desenvolvimento de Algoritmos

## Recursividade em C

Exemplo prático: cálculo de fatorial com animação da pilha

## Objetivo

- Entender o que é **recursividade**
- Visualizar a **pilha de chamadas**
- Compreender vantagens e limitações

---

## Código Fonte

```c
#include <stdio.h>
#include <unistd.h>

// Função recursiva para calcular fatorial e mostrar a pilha
unsigned long long fatorial(int n, int nivel) {
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("-> Chamando fatorial(%d)\n", n);
    usleep(300000);

    if (n == 0 || n == 1) {
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("OK Retornando 1 (caso base)\n");
        usleep(300000);
        return 1;
    } else {
        unsigned long long resultado = n * fatorial(n - 1, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("<- Retornando %llu para fatorial(%d)\n", resultado, n);
        usleep(300000);
        return resultado;
    }
}
int main() {
    int numero;

    printf("Digite um valor inteiro para calcular o fatorial: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Não é possível calcular o fatorial de números negativos.\n");
    } else {
        unsigned long long resultado = fatorial(numero, 0);
        printf("\nO fatorial de %d vale: %llu\n", numero, resultado);
    }

    return 0;
}
```

---

## O que é Recursividade?

- Função que chama a si mesma
- Resolve **subproblemas menores**
- Precisa de **caso base** para terminar

---

## Estrutura de Recursão

1. **Caso base**: termina a recursão (`n == 0 || n == 1`)
2. **Chamada recursiva**: resolve subproblema (`fatorial(n-1)`)
3. **Retorno da pilha**: multiplica resultados e devolve valor final

---

## A pilha de chamadas

- Cada chamada guarda seu contexto (variáveis, endereço de retorno)
- Última chamada a entrar é a primeira a sair (**LIFO**)
- Visualização ajuda a entender fluxo de execução

---

## Demonstração prática (terminal)

- Compile e rode no VS Code:

```bash
gcc -o fatorial_anim fatorial_anim.c
./fatorial_anim
```

- Digite um valor inteiro, ex: `4`
- Saída:

```
  → Chamando fatorial(4)
    → Chamando fatorial(3)
      → Chamando fatorial(2)
        → Chamando fatorial(1)
        ✓ Retornando 1 (caso base)
      ← Retornando 2 para fatorial(2)
    ← Retornando 6 para fatorial(3)
  ← Retornando 24 para fatorial(4)
Fatorial de 4 é: 24
```

---

## Interpretação da animação

- **→ Chamando**: entrada na função
- **✓ Retornando 1**: caso base alcançado
- **← Retornando**: resolução do subproblema
- **Indentação**: profundidade da pilha

---

## Vantagens da Recursão

- Código mais **limpo e expressivo**
- Facilita resolução de problemas naturalmente recursivos
  (árvores, grafos, algoritmos de divisão e conquista)

---

## Desvantagens da Recursão

- Uso de memória extra (pilha)
- Risco de **stack overflow** em recursões profundas
- Às vezes menos eficiente que versão iterativa

---

## Exemplos para praticar

- Fibonacci recursivo
- Soma de elementos de um vetor
- Inversão de string
- Percursos em árvores ou listas encadeadas

---

## Conclusão

- Recursividade = dividir problemas em subproblemas + caso base
- Pilha de chamadas = entender fluxo de execução
- Pratique e visualize a pilha para fixar o conceito

---

# Materiais adicionais

- Apresentação em formato pptx
- Link do vídeo explicativo <https://www.youtube.com/watch?v=BvCdAkDoyXI>
- Link do repositório Github <https://github.com/Silmara-Lima/TDA_in_C>
<<<<<<< HEAD


Estruturas de Controle em C
Exemplo prático: Jogo de Adivinhação integrando Sequência, Condicional e Repetição

Objetivo
Entender Sequência (linearidade) 

Aplicar Condicional (decisão) 

Implementar Repetição (automação) 


Visualizar a integração dos três conceitos 

Código Fonte
C

#include <stdio.h>

int main() {
    // --- 1. SEQUÊNCIA (Linearidade) ---
    // Definição lógica: Declaração antes do uso (Precedência)
    // O computador executa uma linha após a outra, de cima para baixo.
    int numeroSecreto = 42;
    int chute = 0;
    int tentativas = 0;

    printf("=== Jogo de Adivinhacao ===\n");
    printf("Tente adivinhar o numero secreto!\n\n");

    // --- 2. REPETIÇÃO (Loop) ---
    // Mantém o jogo rodando enquanto a condição for verdadeira
    // Pilar 1: Inicialização (já feita acima)
    // Pilar 2: Condição de Parada (chute != numeroSecreto)
    while (chute != numeroSecreto) {
        
        // Pilar 3: Corpo do Loop (o código a repetir)
        printf("Digite seu palpite: ");
        scanf("%d", &chute); // Instrução atômica: leia x
        
        // Pilar 4: Incremento/Atualização
        tentativas++; 

        // --- 3. CONDICIONAL (Decisão) ---
        // Quebra a linearidade verificando uma condição booleana
        if (chute == numeroSecreto) {
            // Bloco "Verdadeiro" (Then)
            printf("\nPARABENS! Voce acertou em %d tentativas.\n", tentativas);
        } 
        else {
            // Bloco "Falso" (Else)
            // Aninhamento de condicionais para dar dicas
            if (chute > numeroSecreto) {
                printf("-> O numero secreto e MENOR.\n");
            } else {
                printf("-> O numero secreto e MAIOR.\n");
            }
        }
    }

    printf("Fim do programa.\n");
    return 0;
}
1. Sequência (O Padrão)

Definição: Estrutura básica onde instruções são executadas uma após a outra, de cima para baixo.


Regra: O computador não pode pular linhas ou inverter a ordem sem comando explícito.

Componentes:


Instruções Atômicas: Comandos individuais (ex: leia x, soma = a+b).



Ordem de Precedência: Declaração vem antes do uso.


2. Condicional (A Escolha)

Definição: Estrutura que quebra a linearidade, permitindo caminhos diferentes.



Mecanismo: Verifica uma Expressão Booleana (Verdadeiro ou Falso).


Estrutura:


Bloco Verdadeiro (Then): Executado se a condição for atendida.



Bloco Falso (Else): Opcional, executado se a condição não for satisfeita.


3. Repetição (A Automação)

Definição: Bloco de código executado repetidamente enquanto uma condição de controle for verdadeira.


Objetivo: Evita escrever a mesma linha de código centenas de vezes.


Os 4 Pilares de um Loop bem feito:


Inicialização: Onde tudo começa (ex: contador).



Condição de Parada: O teste que mantém ou para o loop.



Corpo do Loop: O código que se quer repetir.



Incremento/Atualização: Mudança na variável de controle para evitar loop infinito.


Demonstração prática (terminal)
Compile e rode o código:

Bash

gcc -o jogo_adivinhacao jogo_adivinhacao.c
./jogo_adivinhacao
Simulação de Saída:

=== Jogo de Adivinhacao ===
Tente adivinhar o numero secreto!

Digite seu palpite: 50
-> O numero secreto e MENOR.
Digite seu palpite: 20
-> O numero secreto e MAIOR.
Digite seu palpite: 42

PARABENS! Voce acertou em 3 tentativas.
Fim do programa.
Interpretação do Exemplo
O "Jogo de Adivinhação" é o exemplo perfeito pois as três estruturas trabalham como uma engrenagem única:


Configuração (Sequência): O jogo começa definindo o número secreto.


Loop (Repetição): O programa continua pedindo números até o usuário acertar.


Dicas (Condicional): O programa avalia se o palpite é maior, menor ou igual.

Componentes Críticos

Na Sequência: Rigor na organização; variáveis declaradas no topo são executadas antes do final.



Na Condicional: A expressão (ex: x > 10) é o coração da estrutura.


Na Repetição: A falta do passo de "Atualização" trava o programa (loop infinito).

Conclusão
A programação é construída sobre estes três conceitos fundamentais.

Eles determinam a ordem de execução das instruções do código.

Dominar a interação entre eles (como no jogo) é essencial para algoritmos complexos.

# Materiais adicionais

- Apresentação em formato pptx
- Link do vídeo explicativo <https://youtu.be/7QFFvrBMjp4>
- Link do repositório Github <https://github.com/Silmara-Lima/TDA_in_C>
=======
>>>>>>> 45cd5b0775528d71d4cef390280af30c7c5129d5

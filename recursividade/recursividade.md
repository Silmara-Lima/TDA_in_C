# Recursividade em C

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

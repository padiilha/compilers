# Analisador Léxico com Flex — Projeto de Compiladores

Este projeto implementa um analisador léxico usando **Flex** (Fast Lexical Analyzer Generator) para reconhecer tokens da linguagem definida no trabalho da disciplina de Compiladores.

## 📄 Arquivos principais

- `lexer.l`: arquivo com as regras do analisador léxico (para Flex)
- `entrada_valida.lsi`: exemplo de entrada válida segundo a gramática
- `entrada_invalida.lsi`: exemplo de entrada inválida (com erros léxicos)

## ✅ Pré-requisitos

Você precisa ter o **Flex** e o **g++** instalados:

```bash
sudo apt update
sudo apt install flex g++
```

## ⚙️ Como compilar

```bash
flex lexer.l
g++ -o lexer lex.yy.c
```

Isso gera o executável `lexer`.

## ▶️ Como executar

Execute o programa passando um arquivo `.lsi` com o código-fonte como argumento:

```bash
./lexer entrada_valida.lsi
```

ou

```bash
./lexer entrada_invalida.lsi
```

## 🧪 Saída esperada

- O programa imprime os tokens reconhecidos.
- Em caso de erro léxico, o caractere inválido e a linha correspondente são exibidos.

## ℹ️ Observações

- O analisador ignora comentários iniciados com `#`.
- Espaços, tabs e quebras de linha são ignorados ou usados apenas para contagem de linhas.
- Tokens reconhecidos: palavras-chave, identificadores, números, operadores aritméticos e relacionais, símbolos de agrupamento.

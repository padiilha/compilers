# Analisador Léxico — Projeto de Compiladores

Este projeto implementa um analisador léxico em C++ baseado em diagramas de transição finitos (AFD) para identificar:

- Identificadores (nomes de variáveis ou funções)
- Constantes numéricas inteiras
- Operadores relacionais (`<`, `<=`, `>`, `>=`, `=`, `!=`)
- Palavras-chave reservadas (`if`, `else`, `return`)

## 📁 Estrutura do Projeto

```
.
├── Makefile
├── main.cpp
├── ErrorToken.hh / ErrorToken.cc
├── Lexer.hh / Lexer.cc
├── Token.hh / Token.cc
├── InputBuffer.hh / InputBuffer.cc
├── entrada_valida.txt
└── entrada_invalida.txt
```

## ⚙️ Como compilar

Abra o terminal na pasta do projeto e digite:

```bash
make
```

Isso irá compilar todos os arquivos `.cc` e gerar o executável chamado `lexer`.

## ▶️ Como executar

Você pode passar um arquivo de entrada como argumento, por exemplo:

```bash
./lexer entrada_valida.txt
```

O programa irá:

1. Ler o conteúdo do arquivo.
2. Aplicar a análise léxica.
3. Exibir a lista de tokens encontrados.
4. Exibir a tabela de símbolos (palavras-chave).

## 📌 Observações

- O analisador ignora espaços e quebras de linha.
- Tokens desconhecidos são rotulados como `UNKNOWN`.
- A tabela de símbolos armazena apenas identificadores e palavras-chave.

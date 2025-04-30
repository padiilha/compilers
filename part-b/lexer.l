%{
#include <stdio.h>
#include <stdlib.h>

int num_linha = 1;
%}

%option noyywrap

%%

"def"        { printf("<DEF>\n"); }
"if"         { printf("<IF>\n"); }
"else"       { printf("<ELSE>\n"); }
"print"      { printf("<PRINT>\n"); }
"return"     { printf("<RETURN>\n"); }
"int"        { printf("<INT>\n"); }

"="         { printf("<ASSIGN>\n"); }
"=="         { printf("<EQ>\n"); }
"<="         { printf("<LE>\n"); }
">="         { printf("<GE>\n"); }
"<>"         { printf("<NE>\n"); }
"<"          { printf("<LT>\n"); }
">"          { printf("<GT>\n"); }

"+"          { printf("<PLUS>\n"); }
"-"          { printf("<MINUS>\n"); }
"*"          { printf("<TIMES>\n"); }
"/"          { printf("<DIVIDE>\n"); }

"("          { printf("<LPAREN>\n"); }
")"          { printf("<RPAREN>\n"); }
"{"          { printf("<LBRACE>\n"); }
"}"          { printf("<RBRACE>\n"); }
";"          { printf("<SEMI>\n"); }
","          { printf("<COMMA>\n"); }

[0-9]+       { printf("<NUM, %s>\n", yytext); }
[a-zA-Z_][a-zA-Z_0-9]* { printf("<ID, %s>\n", yytext); }

"#".*        { /* comentário ignorado */ }

[\t ]+       { /* ignora espaços e tabs */ }
\n+          { num_linha++; }

.            { printf("Erro lexico: caractere invalido '%s' na linha %d\n", yytext, num_linha); }

%%

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Uso: %s <arquivo.txt>\n", argv[0]);
    return 1;
  }

  FILE* f = fopen(argv[1], "r");
  if (!f) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  yyin = f;
  yylex();
  fclose(f);
  return 0;
}

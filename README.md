# BuscaBinaria-BlocosDeRua
Este repositório contém um código em C que lê um arquivo binário de blocos de rua, ordenados alfabeticamente, e realiza uma busca binária para encontrar um bloco específico inserido pelo usuário.

## Funcionalidade
O programa é composto por uma struct Bloco que armazena informações como nome do bloco, bairro, região, data, início, local, público e ano do primeiro desfile. Além disso, a função buscaBinaria é responsável por realizar a busca binária no arquivo e encontrar o bloco específico inserido pelo usuário.

## Execução
Para executar o programa, é necessário ter o arquivo binário "BlocosdeRua_2016_ordenado.bin" na mesma pasta do código.

Após baixar os arquivos, basta compilar o programa em um compilador de C e executar o arquivo resultante. Ao executar o programa, será exibida uma lista de todos os blocos de rua presentes no arquivo binário. Em seguida, o usuário deve inserir o nome de um bloco específico para realizar a busca.

Se o bloco for encontrado, o programa exibirá o nome do bloco, a data e o horário de início do desfile. Se o bloco não for encontrado, o programa exibirá uma mensagem informando que o bloco não foi encontrado.

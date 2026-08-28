# Algoritmos e Estrutura de Dados

Repositório de exemplos apresentados em aula e exercícios desenvolvidos na
disciplina de Algoritmos e Estrutura de Dados.

> **Aviso:** este repositório é destinado apenas aos códigos desenvolvidos ou
> apresentados durante as aulas e aos códigos dos exercícios da disciplina.

## Informações da disciplina

| Item | Informação |
| --- | --- |
| Instituição | Anhanguera — OLIM-600 — Ribeirão Preto/SP |
| Curso | Ciência da Computação — Noturno |
| Disciplina | Algoritmos e Estrutura de Dados |
| Docente | Isaias Jose Amaral Soares |
| Coordenador | Fernando Pereira da Silva |
| Turma | 2º semestre — 1262820261A1 |
| Carga horária | 60 horas (50 horas de aula e 10 horas de atividades pré e pós-aula) |

### Objetivo

Desenvolver competências relacionadas à construção e ao uso adequado de
estruturas de dados, com ênfase em listas ligadas e sua aplicação em programas
de computador.

### Conteúdo programático

O plano de ensino está dividido em quatro unidades principais:

1. **Listas ligadas:** definição, dados e ponteiros, percurso, busca, inserção
   e remoção no começo, em posições arbitrárias e no fim; listas duplamente
   ligadas e ordenação.
2. **Pilhas e filas:** definições, regras de operação, verificação de estruturas
   vazias, inserção, remoção, filas circulares e aplicação de pilhas ao problema
   do labirinto.
3. **Tabelas de espalhamento:** motivação, comparação com listas, inserção,
   remoção, busca, tamanho, colisões, qualidade do espalhamento e técnicas de
   otimização.
4. **Armazenamento associativo:** mapas implementados com listas e tabelas de
   espalhamento, incluindo inserção, remoção, consulta e verificação de chaves.

### Metodologia e avaliação

As atividades são organizadas em três momentos: pré-aula, aula e pós-aula. A
metodologia pode envolver aulas expositivas dialogadas, estudos de caso,
trabalhos em grupo, seminários, debates e outras metodologias ativas.

O desempenho é avaliado por atividades e avaliações oficiais, convertidas em
pontos e, ao final do semestre, em uma nota numérica. Datas, valores e regras
são definidos previamente conforme as normas da instituição.

### Bibliografia básica

- ARTEIRO, Marcio Aparecido; SCHEFFER, Vanessa Cadan. *Algoritmos e lógica de
  programação*. Londrina: Editora e Distribuidora Educacional S.A., 2018.
- SCHEFFER, Vanessa Cadan; ARTERO, Marcio Aparecido. *Algoritmos e técnicas de
  programação*. Londrina: Editora e Distribuidora Educacional S.A., 2018.
- ROVAI, Kleber Ricardi. *Algoritmos e estrutura de dados*. Londrina: Editora e
  Distribuidora Educacional S.A., 2018.
- FERRARETO, Leonardo De Marchi; NISHIMURA, Roberto Yukio. *Banco de dados I*.
  Londrina: Editora e Distribuidora Educacional S.A., 2018.
- CAYRES, Carlos Eduardo. *Estrutura de dados*. Londrina: Editora e
  Distribuidora Educacional S.A., 2017.
- MAITINO NETO, Roque. *Programação orientada a objetos*. Londrina: Editora e
  Distribuidora Educacional S.A., 2018.

## Organização

Cada encontro fica em `aulas/AAAA-MM-DD/`. Dentro da aula, os códigos são
agrupados pelo assunto, e não apenas pela ordem em que foram criados:

```text
aulas/
└── AAAA-MM-DD/
    ├── README.md
    └── NN-nome-do-topico/
        ├── README.md
        └── cpp/
            ├── main.cpp
            ├── estrutura.cpp
            └── estrutura.hpp
```

As pastas de linguagem só são criadas quando existe uma implementação naquela
linguagem.

## Aulas

| Data | Conteúdo |
| --- | --- |
| [18/08/2026](aulas/2026-08-18/) | Exercício: implementação de uma lista simplesmente ligada |
| [25/08/2026](aulas/2026-08-25/) | Estudo de pilha e exercício proposto para melhorar uma fila circular |

## Requisitos

- C++: compilador compatível com C++11 ou superior (por exemplo, `g++`).
- C: compilador compatível com C99 ou superior (por exemplo, `gcc`).

Os comandos específicos para compilar e executar cada exemplo estão no README
da respectiva aula.

/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     T_DOUBLE = 259,
     T_INT = 260,
     TRUE = 261,
     FALSE = 262,
     L_PAREN = 263,
     R_PAREN = 264,
     L_SQUARE = 265,
     R_SQUARE = 266,
     COMMA = 267,
     EQ = 268,
     NEQ = 269,
     LTE = 270,
     LT = 271,
     GTE = 272,
     GT = 273,
     MUL = 274,
     ADD = 275,
     SUB = 276,
     DIV = 277,
     NEG = 278,
     AND = 279,
     OR = 280,
     NEXT = 281,
     FUTURE = 282,
     GLOBAL = 283,
     UNTIL = 284,
     UNKN = 285,
     ENDOFFILE = 286
   };
#endif
/* Tokens.  */
#define ID 258
#define T_DOUBLE 259
#define T_INT 260
#define TRUE 261
#define FALSE 262
#define L_PAREN 263
#define R_PAREN 264
#define L_SQUARE 265
#define R_SQUARE 266
#define COMMA 267
#define EQ 268
#define NEQ 269
#define LTE 270
#define LT 271
#define GTE 272
#define GT 273
#define MUL 274
#define ADD 275
#define SUB 276
#define DIV 277
#define NEG 278
#define AND 279
#define OR 280
#define NEXT 281
#define FUTURE 282
#define GLOBAL 283
#define UNTIL 284
#define UNKN 285
#define ENDOFFILE 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 75 "parser.ypp"
{
  double constant;
  Node *tree_node;
}
/* Line 1529 of yacc.c.  */
#line 116 "parser.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


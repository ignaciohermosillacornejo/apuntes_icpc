.PHONY: all clean lint

LATEX ?= pdflatex
VPATH = Notes
BUILDDIR = Notes

all: main.pdf

clean:
	cd $(BUILDDIR) && latexmk -C

lint:
	npx eclint check *.cls *.sty *.tex 

%.pdf: %.tex
	cd $(BUILDDIR) && pwd && latexmk -synctex=1 --interaction=nonstopmode -pdf- -shell-escape --pdflatex=$(LATEX) ../$< && latexmk -synctex=1 --interaction=nonstopmode -pdf -shell-escape --pdflatex=$(LATEX) ../$<
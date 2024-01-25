TEX_FILE = Ex1.tex
PDF_FILE = $(patsubst %.tex, %.pdf, $(TEX_FILE))

all: $(PDF_FILE)

$(PDF_FILE): $(TEX_FILE)
	pdflatex $(TEX_FILE)
	bibtex $(patsubst %.tex, %, $(TEX_FILE))
	pdflatex $(TEX_FILE)
	pdflatex $(TEX_FILE)

clean:
	rm -f *.aux *.bbl *.blg *.log *.out *.pdf

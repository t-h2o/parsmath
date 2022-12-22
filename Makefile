diagram:
	asciidoctor -r asciidoctor-diagram assets/README.adoc -o assets/index.html

doc: diagram
	asciidoctor README.adoc -o index.html

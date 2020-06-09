all: a.out bacon.class

a.out: /public/java_bridges/a.out
	cp /public/java_bridges/a.out .

bacon.class: bacon.java
	javac bacon.java

clean:
	rm bacon.class

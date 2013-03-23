#Mode d'emploi

#make : compile tous les fichiers .c en .o et .asm en .o puis crée les liens vers exécutable

#crée fichier exe C à partir de toutes les sources C présentes dans le dossier
#make e=nom_de_l_executable_C

#crée fichier exe C à partir des sources voulues
#make e=nom_de_l_executable_C s="fichier1.c fichier2.c (2 fichiers à 999)"



############# VARIABLES POUR COMPILATION C ####################
#nom du linker
LD = gcc
#nom du compilateur
CC = gcc 
#liste des paramètre à passer à GCC pour la création du fichier objet
CFLAGS = -c -g -Wall -ansi
#on récupère la liste des fichiers c
SRC = $(wildcard *.c)
#on crée la liste des fichiers .o qu'on souhaite créer à partir des .c
C_OBJS = $(patsubst %.c,%.o,$(SRC))
#on crée la liste des exécutables qu'on souhaite créer en remplaçant fichier.c par fichier
C_EXE = $(SRC:%.c=%)

############# VARIABLES POUR COMPILATION ASM ####################
#liste des paramètre à passer à Nasm pour la création du fichier objet
NASMFLAGS = -g -f elf -F dwarf
#on récupère la liste des fichiers asm
ASM = $(wildcard *.asm)
#on crée la liste des fichiers .o qu'on souhaite créer à partir des .c
ASM_OBJS = $(patsubst %.asm,%.o,$(ASM))
#liste des exe à créer à partir asm
ASM_EXE = $(ASM:%.asm=%)


ifdef e
e = $(word 1, $(ARGS))

#make e=nom_executable s=sources_necessaires
ifdef s

s= $(wordlist 2, 999, $(ARGS))
OBJS_EXE = $(patsubst %.c,%.o,$(s))

all: $(e)

$(e): $(OBJS_EXE)
	@$(LD) $(OBJS_EXE) -o $@
	
%.o:%.c
	@$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(OBJS_EXE)

#make e
else
all: $(e)

$(e): $(C_OBJS)
	@$(LD) $(C_OBJS) -o $@
	
%.o:%.c
	@$(CC) $(CFLAGS) $<

clean:
	rm -f $(e) $(C_OBJS)
endif

#make
else

all: ${C_EXE} ${ASM_EXE}

#crée dynamiquement les règles de création d'exécutables C
${C_EXE}: $(C_OBJS)
	@$(LD) $@.o -o $@
	@chmod +x $@
	
#crée dynamiquement les règles de création d'exécutables ASM
${ASM_EXE}: $(ASM_OBJS)
	@ld $@.o asm_io.o -e main -o $@
	@chmod +x $@
	
asm_io:
		
#crée fichiers .o correspondant aux fichiers .c
%.o:%.c
	@$(CC) $(CFLAGS) $<

#crée fichiers .o correspondant aux fichiers .asm
%.o:%.asm
	@nasm -g -f elf $< -F dwarf 

#clean tous les exe C et les objets nécessaires au linkage des exe C
clean:
	rm -f $(C_EXE) $(C_OBJS)
endif 

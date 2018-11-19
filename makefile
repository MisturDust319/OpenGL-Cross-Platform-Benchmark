target       := a.out
sources      := src/main.cpp src/FPShistory.cpp src/history.cpp src/shader.cpp src/shapes.cpp src/cube.cpp

includes     := . include

objects      := $(subst .cpp,.o,$(sources))
objects      := $(subst .c,.o,$(objects))

override src_path := $(src_path) $(includes)
override lib_path := $(lib_path) -Llib/GLFW
override libs     := $(libs) -lglut -lglu -lgl -lGLEW
# possible libs: -lglfw3dll
# (glfw)

DEBUG        := yes

CC           := gcc
CXX          := g++
LNK          := g++

DEFINES      := 
CDEFINES     := $(DEFINES)
CXXDEFINES   := $(DEFINES)

CFLAGS       := $(CDEFINES)
CXXFLAGS     := $(CXXDEFINES)
LFLAGS       := $(lib_path) $(libs) -mwindows -L.
#For OSX: gcc -framework OpenGL -o my_opengl_program my_opengl_program.c

OUTPUT_OPTION = -o $@

vpath %.cpp  $(src_path)
vpath %.c    $(src_path)
vpath %.h    $(src_path)

CPPFLAGS     := $(addprefix -I ,$(src_path))

ifeq "$(DEBUG)" "yes"
%.o: CXXFLAGS+=-g -O0
%.o: CFLAGS+=-g -O0
else
%.o: CXXFLAGS+=-O2
%.o: CFLAGS+=-O2
endif

COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $<
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c $<
COMPILE.cpp = $(COMPILE.cc)

all: $(target)

$(target): $(objects)
	@echo Linking ..
	
	@echo -n "  "
	@echo $(LNK) $(LFLAGS) $(objects) $(OUTPUT_OPTION) $(TARGET_ARCH)
	
	@$(LNK) $(objects) $(OUTPUT_OPTION) $(TARGET_ARCH) $(LFLAGS) || \
		(echo "Compilation failed"; exit 1)
	
	@echo "Compilation success"

%.o: %.c
	@echo "Recompiling object file for .. $< $(COMPILE.cc) $(OUTPUT_OPTION)"
	
	@$(COMPILE.c) $(OUTPUT_OPTION) || (echo "Compilation failed"; exit 1)

%.o: %.cpp
	@echo "Recompiling object file for .. $< $(COMPILE.cc) $(OUTPUT_OPTION)"
	
	@$(COMPILE.cc) $(OUTPUT_OPTION) || (echo "Compilation failed"; exit 1)

.PHONY:
clean:
	$(RM) *.o src/*.o

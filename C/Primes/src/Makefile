# compiler flags
DEBUG    = -ggdb
OPTIMISE = -O0
WARNINGS = -Wall -Wextra -Wno-variadic-macros -Wno-overlength-strings -pedantic
CFLAGS   = $(DEBUG) $(OPTIMISE) $(WARNINGS)
DFLAGS   = # -DDEBUG_PARSER -DDEBUG_SYMBOL_TABLE -DDEBUG_HASH_TABLE

CC       = clang
RM       = rm -f
COMPILE  = $(CC) $(CFLAGS) $(DFLAGS)
INSTALL  = install

# files
EXES     = primes

# directories
BINDIR   = ../bin
LOCALBIN = ~/.local/bin

# executables

primes: primes.c | $(BINDIR)
	$(COMPILE) -o $(BINDIR)/$@ $^
# BINDIR

$(BINDIR):
	mkdir $(BINDIR)

### PHONY TARGETS ##############################################################

.PHONY: all clean install uninstall types

all: primes 

clean:
	$(RM) $(foreach EXEFILE, $(EXES), $(BINDIR)/$(EXEFILE))
	$(RM) *.o
	$(RM) -rf $(BINDIR)/*.dSYM

# Install all compiler-related binaries in the local bin.
install:
	mkdir -p $(LOCALBIN)
	$(INSTALL) $(foreach EXEFILE, $(EXES), $(wildcard $(BINDIR)/$(EXEFILE))) \
		$(LOCALBIN)

# Remove all compiler-related binaries from the local bin.
uninstall:
	$(RM) $(foreach EXEFILE, $(EXES), $(LOCALBIN)/$(EXEFILE))

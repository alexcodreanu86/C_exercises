#Set this to @ to keep the makefile quiet
SILENCE = @
#---- Outputs ----#
COMPONENT_NAME = Exercises


TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a

TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = Gcc

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src \
	$(PROJECT_HOME_DIR)/src/** \

TEST_SRC_DIRS = \
	spec\
	spec/*\
	spec/**/**\

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  $(PROJECT_HOME_DIR)/include\
	$(PROJECT_HOME_DIR)/include/** \

CPPUTEST_WARNINGFLAGS += -Wall -Werror -Wswitch-default -Wswitch-enum -Wno-c++11-long-long


include $(CPPUTEST_HOME)/build/MakefileWorker.mk

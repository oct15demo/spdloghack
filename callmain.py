from ctypes import *

c_program = "a.out"
c_loaded_program = CDLL(c_program)
main = c_loaded_program.main

main()

env = Environment()
env['PCHSTOP'] = 'stdafx.h' # indicates header used to generate precompiled header file (VC++ only, ignored otherwise)
env['PCH'] = env.PCH('stdafx.cpp')[0] # generates precompiled header file (VC++ only, ignored otherwise)
env.Program(target = '../ZPR', source = ["main.cpp"])
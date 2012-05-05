env = Environment()

if env.get('PCHSTOP'):
	env['PCHSTOP'] = 'stdafx.h'  #indicates header used to generate precompiled header file (VC++ only, ignored otherwise)
if env.get('PCH'):
	env['PCH'] = env.PCH('stdafx.cpp')[0]  #generates precompiled header file (VC++ only, ignored otherwise)

env.Program(target = '../ZPR', source = ["main.cpp"])

env = Environment()

if hasattr(env, "PCH"):
	env['PCHSTOP'] = 'stdafx.h'  #indicates header used to generate precompiled header file (VC++ only, ignored otherwise)
	env['PCH'] = env.PCH('stdafx.cpp')[0]  #generates precompiled header file (VC++ only, ignored otherwise)
	env.Append(CCFLAGS = '/EHsc')

env['CPPPATH'] = ['neur/include', '.']

env.Program(target = '../ZPR', source = ['neur/src/neuron.cpp','neur/src/network.cpp','main.cpp'])

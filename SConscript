# SCons script using dynamic linking with boost_unit_test_framework
import platform

env = Environment()

env['CPPPATH'] = ['.', 'neur/include', 'learn/include', 
	'media/include', 'contrib/fftw-3.3.1/api', '../boost']
    
if(platform.system() == "Windows"):
	env['LIBS'] = 'libfftw3f-3'
	env['LIBPATH'] = ['../boost/stage/lib', 'contrib/fftw-3.3.1/win32libs']
	env['CPPFLAGS'] = ' /EHsc /MD'
	env['LINKFLAGS'] = ' /SUBSYSTEM:CONSOLE'
	if hasattr(env, "PCH"):
		env['PCHSTOP'] = 'stdafx.h'  #indicates header used to generate precompiled header file (VC++ only, ignored otherwise)
		env['PCH'] = env.PCH('stdafx.cpp')[0]  #generates precompiled header file (VC++ only, ignored otherwise)
else:
	env['LIBPATH'] = 'contrib/fftw-3.3.1/libs'
	env['LIBS'] = ['boost_thread', 'boost_unit_test_framework', 'boost_system', 'boost_filesystem', 'fftw3f']

env.Program(target = '../ZPR', source = ['main.cpp', 'myApp.cpp',
	'media/src/audioSample.cpp', 'media/src/fft.cpp', 'media/src/waveReader.cpp',
    'learn/src/learningSetReader.cpp', 'learn/src/teacher.cpp', 
	'neur/src/baseNeuron.cpp', 'neur/src/layer.cpp'])
	
env['PCHSTOP'] = ''
env['PCH'] = ''

env.Program(target = '../WaveReaderTest', source = ['media/src/waveReader.cpp',
	'media/src/audioSample.cpp', 'tests/WaveReaderTest/WaveReaderTest.cpp'])

env.Program(target = '../neurTest', source = ['neur/src/layer.cpp',
	'neur/src/baseNeuron.cpp', 'tests/neurTest/neurTest.cpp'])

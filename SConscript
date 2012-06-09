# SCons script using dynamic linking with boost_unit_test_framework
import platform, os

env = Environment()

if hasattr(env, "PCH"):
	env['PCHSTOP'] = 'stdafx.h'  #indicates header used to generate precompiled header file (VC++ only, ignored otherwise)
	env['PCH'] = env.PCH('stdafx.cpp')[0]  #generates precompiled header file (VC++ only, ignored otherwise)
	env.Append(CCFLAGS = '/EHsc')

env['CPPPATH'] = ['.', 'neur/include', 'learn/include', 
	'media/include', 'contrib/fftw-3.3.1/api']

if(platform.system() == "Linux"):
    #Linux - indicates library boost_unit_test to link with
    env['LIBS'] = ['boost_unit_test_framework']

"""
TODO do zbudowania reszta testow oraz aplikacja
env.Program(target = '../ZPR', source = ['main.cpp', 'neur/src/neuron.cpp','neur/src/network.cpp', 
	'media/src/audioSample.cpp', 'media/src/fft.cpp', 'media/src/soundReader.cpp',
	'media/src/waveReader.cpp', 'learn/src/learningSetReader.cpp', 'learn/src/teacher.cpp',
	'tests/neurTest/neurTest.cpp'])
"""

env.Program(target = '../WaveReaderTest', source = ['media/src/waveReader.cpp',
	'media/src/audioSample.cpp', 'tests/WaveReaderTest/WaveReaderTest.cpp'])

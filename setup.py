#!/usr/bin/env python

from setuptools import setup, find_packages, Extension

setup(
	name='pyaquestalk2',
	version='1.0.0',
	description='AquesTalk2 python binding',
	author='kenboo',
	author_email='kenbooing@gmail.com',
	url='http://com.nicovideo.jp/community/co475423',
	packages=find_packages(),
	long_description = """\
	This is a Python binding for AquesTalk2.
	AquesTalk2 is a human voice synthesizer developed by
	AQUEST Corp in Japan. http://www.a-quest.com
	""",
	classifiers = [
		"License :: OSI Approved :: GNU General Public License",
		"Programming Language :: Python",
		"Development Status :: 4 - Beta",
		"Intended Audience :: Developers",
		"Topic :: dropship",
	],
	keywords='voice sythesizer',
	license='GPL',
	install_requires = [
		'setuptools'
	],
	ext_modules=[Extension('aquestalk2',
                               ['aquestalk2.c'],
                               extra_link_args=['-lAquesTalk2'],
                               ),
                     ],
	test_suite = 'nose.collector',
)

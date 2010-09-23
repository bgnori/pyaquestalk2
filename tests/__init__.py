# -*- coding: utf-8 -*-
import unittest
import aquestalk2

class AquesTalkTestCase(unittest.TestCase):
    def setUp(self):
        pass

    def test_synthe(self):
        wav = aquestalk2.synthe('あくえすとーく')
	self.assert_(len(wav) > 1000)

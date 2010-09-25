# -*- coding: utf-8 -*-
import unittest
import aquestalk2
import aquestalk2.yahoo

class AquesTalkTestCase(unittest.TestCase):
    def setUp(self):
        pass

    def test_synthe(self):
        wav = aquestalk2.synthe('あくえすとーく')
	self.assert_(len(wav) > 1000)

    def test_parse(self):
        sentence = "野球帽をかぶった船長はチャーター機のタラップを降りる際、両手を挙げてＶサインを作った。"
        phonetic = 'やきゅうぼうお/かぶったせんちょうわ、ちゃーたーきのたらっぷお/おりるさい、りょうてお/あケ゜て;ぶいさいんお/つくった。'
        result = aquestalk2.yahoo.to_phonetic(sentence)
        self.assertEqual(result, phonetic)

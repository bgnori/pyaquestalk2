# -*- coding: utf-8 -*-
import urllib, urllib2
from jcconv import half2wide
import result_set

YAHOO_APP_ID='F0bd9VOxg67v_QBajUI0zjDKrpC_nculhfOlHGvU6qyPQg9Pvd6uSA4H7aiK'
YAHOO_PARSER='http://jlp.yahooapis.jp/MAService/V1/parse'

def call_parser(sentence):
    params = dict(appid=YAHOO_APP_ID,
                  sentence=sentence)
    url = YAHOO_PARSER + '?' + urllib.urlencode(params)
    request = urllib2.Request(url)
    content = urllib2.urlopen(request).read()
    return content

def to_phonetic(sentence):
    """
    takes UTF-8 string
    returns UTF-8 string
    """
    xml = call_parser(half2wide(sentence))
    rs = result_set.parseString(xml)
    res = []
    for word in rs.ma_result.word_list.word:
        if word.pos == u'助詞':
            if word.reading == u'は':
                res.append(u'わ、')
            elif word.reading == u'を':
                res.append(u'お/')
            elif word.reading == u'て':
                res.append(u'て;')
            else:
                res.append(word.reading)
        else:
            res.append(word.reading)
    res = ''.join(res)

    # post processing
    res = res.replace(u'げ', u'ケ゜')
    return res.encode('utf-8')


if __name__=='__main__':
    sentence = "野球帽をかぶった船長はチャーター機のタラップを降りる際、両手を挙げてＶサインを作った。"
    phonetic = 'やきゅうぼうお/かぶったせんちょうわ、ちゃーたーきのたらっぷお/おりるさい、りょうてお/あケ゜て;ぶいさいんお/つくった。'
    result = to_phonetic(sentence)
    print result == phonetic

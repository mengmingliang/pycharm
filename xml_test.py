from xml.parsers.expat import ParserCreate

#xml data is for here
data = r'''<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<rss version="2.0" xmlns:yweather="http://xml.weather.yahoo.com/ns/rss/1.0" xmlns:geo="http://www.w3.org/2003/01/geo/wgs84_pos#">
    <channel>
        <title>Yahoo! Weather - Beijing, CN</title>
        <lastBuildDate>Wed, 27 May 2015 11:00 am CST</lastBuildDate>
        <yweather:location city="Beijing" region="" country="China"/>
        <yweather:units temperature="C" distance="km" pressure="mb" speed="km/h"/>
        <yweather:wind chill="28" direction="180" speed="14.48" />
        <yweather:atmosphere humidity="53" visibility="2.61" pressure="1006.1" rising="0" />
        <yweather:astronomy sunrise="4:51 am" sunset="7:32 pm"/>
        <item>
            <geo:lat>39.91</geo:lat>
            <geo:long>116.39</geo:long>
            <pubDate>Wed, 27 May 2015 11:00 am CST</pubDate>
            <yweather:condition text="Haze" code="21" temp="28" date="Wed, 27 May 2015 11:00 am CST" />
            <yweather:forecast day="Wed" date="27 May 2015" low="20" high="33" text="Partly Cloudy" code="30" />
            <yweather:forecast day="Thu" date="28 May 2015" low="21" high="34" text="Sunny" code="32" />
            <yweather:forecast day="Fri" date="29 May 2015" low="18" high="25" text="AM Showers" code="39" />
            <yweather:forecast day="Sat" date="30 May 2015" low="18" high="32" text="Sunny" code="32" />
            <yweather:forecast day="Sun" date="31 May 2015" low="20" high="37" text="Sunny" code="32" />
        </item>
    </channel>
</rss>
'''

class WeatherSaxHandler(object):
    _data = {}
    _day_cnt = 0
    def __init(self):
        self._data = {}
        self._day_cnt = 0

    @property
    def data(self):
        return self._data

    def start_element(self, name, attrs):
        if name == 'yweather:location':
            self._data['city'] = attrs['city']
            self._data['country'] = attrs['country']
            self._data['region'] = attrs['region']
        if name == 'yweather:forecast':
            if self._day_cnt == 0:
                self._data['today'] = {}
                self._data['today']['text'] = attrs['text']
                self._data['today']['low'] = attrs['low']
                self._data['today']['high'] = attrs['high']
                self._day_cnt = self._day_cnt+1
            if  self._day_cnt == 1:
                self._data['tomorrow'] = {}
                self._data['tomorrow']['text'] = attrs['text']
                self._data['tomorrow']['low'] = attrs['low']
                self._data['tomorrow']['high'] = attrs['high']
                self._day_cnt = self._day_cnt + 1

    def end_element(self, name):
        return name

    def char_data(self, text):
        return text

def parse_weather(xml):
    handler = WeatherSaxHandler()
    parser = ParserCreate()
    parser.StartElementHandler = handler.start_element
    parser.EndElementHandler = handler.end_element
    parser.CharacterDataHandler = handler.char_data
    parser.Parse(xml)
    return handler.data

print(parse_weather(data))


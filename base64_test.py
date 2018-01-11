#encode and decode by base64 coding
import base64
encode_str = base64.b64encode(b'binary\x00string')
print(encode_str)
decode_str = base64.b64decode(encode_str)
print(decode_str)
encode_url_str = base64.b64encode(b'i\xb7\x1d\xfb\xef\xff')
print(encode_url_str)
#safe decode by base64
def safe_base64_decode(s):
    s = s + b'='*(4-len(s)%4)
    return base64.b64decode(s)

assert b'abcd' == safe_base64_decode(b'YWJjZA==')
assert b'abcd' == safe_base64_decode(b'YWJjZA')


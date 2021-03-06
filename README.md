# HTML-Attribute-Parser
The program can parse all different attributes of different tags used in any HTML / HRML code.

The opening tags follow the format:

\<tag-name attribute1-name = "value1" attribute2-name = "value2" ...\>

The closing tags follow the format:

\</tag-name\>

The attributes are referenced as:

tag1\~value

tag1.tag2\~name

Given the source code in HRML format consisting of N lines, it'll answer Q queries.  For each query, it'll print the value of the attribute specified.  It'll print "Not Found!" if the attribute does not exist.

Example:

**HRML listing**

\<tag1 value = "value"\>

\<tag2 name = "name"\>

\<tag3 another="another" final="final"\>

</tag3>

</tag2>

</tag1>

**Queries**

tag1\~value

tag1.tag2.tag3\~name

tag1.tag2\~value

Here, tag2 is nested within tag1, so attributes of tag2 are accessed as tag1.tag2~<attribute>. Results of the queries are:

tag1~value:              "value"

tag1.tag2.tag3~name:    "Not Found!"

tag1.tag2.tag3~final:    "final"

**Input Format**

The first line consists of two space separated integers, N and Q. N specifies the number of lines in the HRML source program. Q specifies the number of queries.

The following  lines consist of either an opening tag with zero or more attributes or a closing tag. If there are no attributes there is no space after tag name. Q queries follow in the above specified format.

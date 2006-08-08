/*
Copyright (c) 2006 The FlameRobin Development Team

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


  $Id$

*/
//-----------------------------------------------------------------------------
#ifndef FR_MULTI_STATEMENT_H
#define FR_MULTI_STATEMENT_H
//-----------------------------------------------------------------------------
class SingleStatement
{
private:
    wxString sqlM;
    wxString thirdStringM;
    bool isValidM;
    enum StatementType { stCommit, stRollback, stSetTerm, stSetAutoDDL,
         stOther } typeM;

public:
    SingleStatement(const wxString& sql, bool valid = true);

    bool isCommitStatement() const;
    bool isRollbackStatement() const;
    bool isSetTermStatement(wxString& newTerm) const;
    bool isSetAutoDDLStatement(wxString& newSetting) const;
    bool isValid() const;

    wxString getSql() const;
};
//-----------------------------------------------------------------------------
class MultiStatement
{
private:
    wxString::size_type oldPosM;
    wxString::size_type searchPosM;
    wxString::size_type lastPosM;

    bool atEndM;
    const wxString& sqlM;
    wxString terminatorM;
public:
    MultiStatement(const wxString& sql, const wxString& terminator = wxT(";"));

    SingleStatement getNextStatement();
    SingleStatement getStatementAt(int position);

    // get positions of last statement retrieved
    int getStart() const;
    int getEnd() const;

    wxString getTerminator() const;
    void setTerminator(const wxString& newTerm);
};
//-----------------------------------------------------------------------------
#endif
package kawigi.language;
import kawigi.problem.*;

public class VBTestGenerator implements TestGenerator
{
	/**
	 *	Returns VB.NET testing code for the problem statement's example test
	 *	cases.
	 **/
	public String getCode(ClassDecl cl)
	{
		String testcode = "#Region \"Testing code generated by KawigiEdit\"\n";
		testcode += "Module MainModule\n";
		testcode += "\tSub Main()\n";
		EditorDataType returnType = cl.getMethod().getReturnType();
		testcode += "\t\tDim Errors As Boolean = False\n";
		testcode += "\t\tDim Answer, DesiredAnswer As " + EditorLanguage.VB.getName(returnType) + "\n";
		testcode += "\t\tDim Obj As " + cl.getName() + "\n";
		testcode += "\t\tDim Time As DateTime\n";
		if (returnType.isArrayType())
		{
			testcode += "\t\tDim Same As Boolean\n";
			testcode += "\t\tDim i As Integer\n";
		}
		boolean stringType = returnType.isType(EditorDataType.String);
		EditorDataType[] paramTypes = cl.getMethod().getParamTypes();
		testcode += "\t\t<%:start-tests%>\n";
		for (int i=0; i<cl.countTests(); i++)
		{
			testcode += "\t\tObj = New " + cl.getName() + "()\n";
			testcode += "\t\tTime = DateTime.Now\n";
			testcode += "\t\tAnswer = Obj." + cl.getMethod().getName() + "(" + toTest(cl.getTest(i).getParameters(), paramTypes) + ")\n";
			testcode += "\t\tConsole.WriteLine(\"Time: \" & (DateTime.Now.Subtract(Time)).TotalSeconds & \" seconds\")\n";
			testcode += "\t\tDesiredAnswer = " + translateObject(returnType, cl.getTest(i).getAnswer()) + "\n";
			testcode += "\t\tConsole.WriteLine(\"Your Answer:\")\n";
			if (returnType.isArrayType())
			{
				testcode += "\t\tConsole.Write(\"{ \")\n";
				testcode += "\t\tIf (Answer.Length > 0) Then\n";
				testcode += "\t\t\tConsole.Write(" + (stringType ? "\"\"\"\" & " : "") + "Answer(0)" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\t\tFor i = 1 To Answer.Length - 1\n";
				testcode += "\t\t\t\tConsole.Write(\"\t, " + (stringType ? "\"\"" : "") + "\" & Answer(i)" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\t\tNext\n";
				testcode += "\t\t\tConsole.WriteLine(\" }\")\n";
				testcode += "\t\tElse\n";
				testcode += "\t\t\tConsole.WriteLine(\"}\")\n";
				testcode += "\t\tEnd If\n";
				testcode += "\t\tConsole.WriteLine(\"Desired Answer:\")\n";
				testcode += "\t\tConsole.Write(\"{ \")\n";
				testcode += "\t\tIf (DesiredAnswer.Length > 0) Then\n";
				testcode += "\t\t\tConsole.Write(" + (stringType ? "\"\"\"\" & " : "") + "DesiredAnswer(0)" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\t\tFor i = 1 To DesiredAnswer.Length - 1\n";
				testcode += "\t\t\t\tConsole.Write(\", " + (stringType ? "\"\"" : "") + "\" & DesiredAnswer(i)" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\t\tNext\n";
				testcode += "\t\t\tConsole.WriteLine(\" }\")\n";
				testcode += "\t\tElse\n";
				testcode += "\t\t\tConsole.WriteLine(\"}\")\n";
				testcode += "\t\tEnd If\n";
				testcode += "\t\tSame = (Answer.Length = DesiredAnswer.Length)\n";
				testcode += "\t\tIf (Same)\n";
				testcode += "\t\t\tFor i = 0 To DesiredAnswer.Length - 1\n";
				testcode += "\t\t\t\tIf Answer(i) <> DesiredAnswer(i) Then\n";
				testcode += "\t\t\t\t\tSame = False\n";
				testcode += "\t\t\t\tEnd If\n";
				testcode += "\t\t\tNext\n";
				testcode += "\t\tEnd If\n";
				testcode += "\t\tIf Same Then\n";
				testcode += "\t\t\tConsole.WriteLine(\"Match :-)\")\n";
				testcode += "\t\tElse\n";
				testcode += "\t\t\tConsole.WriteLine(\"DOESN'T MATCH!!!!\")\n";
				testcode += "\t\t\tErrors = True\n";
				testcode += "\t\tEnd If\n";
			}
			else
			{
				testcode += "\t\tConsole.WriteLine(\"\t" + (stringType ? "\"\"" : "") + "\" & Answer" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\tConsole.WriteLine(\"Desired Answer:\")\n";
				testcode += "\t\tConsole.WriteLine(\"\t" + (stringType ? "\"\"" : "") +"\" & DesiredAnswer" + (stringType ? " & \"\"\"\"" : "") + ")\n";
				testcode += "\t\tIf Answer = DesiredAnswer Then\n";
				testcode += "\t\t\tConsole.WriteLine(\"Match :-)\")\n";
				testcode += "\t\tElse\n";
				testcode += "\t\t\tConsole.WriteLine(\"DOESN'T MATCH!!!!\")\n";
				testcode += "\t\t\tErrors = True\n";
				testcode += "\t\tEnd If\n";
			}
			testcode += "\t\tConsole.WriteLine()\n";
		}
		testcode += "\t\t<%:end-tests%>\n";
		testcode += "\t\t\n\t\tIf Errors Then\n";
		testcode += "\t\t\tConsole.WriteLine(\"Some of the test cases had errors :-(\")\n";
		testcode += "\t\tElse\n";
		testcode += "\t\t\tConsole.WriteLine(\"You're a stud (at least on the test data)! :-D \")\n";
		testcode += "\t\tEnd If\n";
		testcode += "\tEnd Sub\n";
		testcode += "End Module\n";
		testcode += "#End Region\n";
		return testcode;
	}
	
	/**
	 *	Quick utility function to provide the code that should return the
	 *	parameter list for the function.
	 **/
	protected String toTest(String[] input, EditorDataType[] types)
	{
		String ret = translateObject(types[0], input[0]);
		for (int i=1; i<input.length; i++)
			ret += ", " + translateObject(types[i], input[i]);
		ret = ret.replaceAll("\\n", "");
		return ret;
	}
	
	/**
	 *	Quck utility function to convert a string value from TC to code that
	 *	creates that value in VB.
	 **/
	protected static String translateObject(EditorDataType type, String value)
	{
		if (type.isArrayType())
			return "New " + EditorLanguage.VB.getName(type) + EditorLanguage.VB.fixLiteral(value, type);
		else
			return EditorLanguage.VB.fixLiteral(value, type);
	}
}

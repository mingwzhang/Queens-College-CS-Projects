//Mingwei Zhang

package TJasn.virtualMachine;

import TJasn.TJ;

public class WRITESTRINGinstr extends TwoOperandInstruction {

  void execute ()
  {
    for(int x = firstOperand; x <= secondOperand; x++)
    {
        System.out.print((char) TJ.data[x]);
    }
  }

  public WRITESTRINGinstr (int startOffset, int endOffset)
  {
    super(startOffset, endOffset, "WRITESTRING");
  }
}
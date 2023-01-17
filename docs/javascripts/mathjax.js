window.MathJax = {
  tex: {
    inlineMath: [["\\(", "\\)"]],
    displayMath: [["\\[", "\\]"]],
    processEscapes: true,
    processEnvironments: true,
    macros: {
      N: "{\\mathbb{N}}",
      Z: "{\\mathbb{Z}}",
      Q: "{\\mathbb{Q}}",
      R: "{\\mathbb{R}}",
      I: "{\\mathbb{I}}",
      C: "{\\mathbb{C}}",
      mcd: "{\\mathop{\\rm mcd}\\nolimits}",
      set: ["\\left\\{\\, #1 \\,\\right\\}", 1],
      dom: "{\\mathop{\\rm dom\\,}\\nolimits}",
      codom: "{\\mathop{\\rm codom\\,}\\nolimits}",
      tc: "{\\hspace{0.5em}\\text{t.c.}\\hspace{0.5em}}",
      ll: "{\\mathcal{L}}",
      llo: "{\\mathcal{L}_O\\hspace{0.1em}}",
      mm: "{\\mathcal{M}}",
      ml: "{\\mathcal{M}_{\\hspace{-0.10em}\\mathcal{L}}\\hspace{0.1em}}",
      mlp: "{{\\mathcal{M}'}_{\\hspace{-0.45em}\\mathcal{L}^{'}}\\hspace{0.1em}}",
      molo: "{{\\mathcal{M}_O}_{\\hspace{-0.1em}\\mathcal{L}_O}\\hspace{0.1em}}",
      prgm: "{\\mathcal{P}}",
      intr: "{\\mathcal{I}}",
      cmp: "\\mathcal{C}",
      prgmcomp: "{\\mathcal{Pc}}",
      sx: "{\\mathrm{\\,Sx\\,}}",
      dx: "{\\mathrm{\\,Dx\\,}}",
      caret: "{\\;\\hat{}\\;}"
    },
  },
  options: {
    ignoreHtmlClass: ".*|",
    processHtmlClass: "arithmatex",
  },
};

document$.subscribe(() => {
  MathJax.typesetPromise();
});

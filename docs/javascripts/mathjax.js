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

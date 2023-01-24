window.MathJax = {
    tex: {
        inlineMath: [["\\(", "\\)"]],
        displayMath: [["\\[", "\\]"]],
        processEscapes: true,
        processEnvironments: true,
        loader: {load: ['[tex]/textmacros']},
        tex: {packages: {'[+]': ['textmacros']}},
        macros: {
            // numerical sets
            N: "{\\mathbb{N}}",
            Z: "{\\mathbb{Z}}",
            Q: "{\\mathbb{Q}}",
            R: "{\\mathbb{R}}",
            I: "{\\mathbb{I}}",
            C: "{\\mathbb{C}}",

            // math operators
            mcd: "{\\mathop{\\rm mcd}\\nolimits}",
            dom: "{\\mathop{\\rm dom}\\nolimits}",
            codom: "{\\mathop{\\rm codom}\\nolimits}",

            // so that
            tc: "{\\hspace\{.4em}\\text{t.c.}\\hspace\{.4em}}",

            // better set notation
            set: ["{\\left\\{\\hspace\{.1em} #1 \\hspace\{.1em}\\right\\}}", 1],

            // LdP macros
            lng: "{\\mathcal{L}}",
            llo: "{\\mathcal{L}_{\\hspace{-.08em}O} \\hspace\{.1em}}",

            mm: "{\\mathcal{M}}",
            ml: "{{\\mm}_{\\hspace{-.15em} \\lng} \\hspace\{.1em}}",
            mlprime: "{{\\mm'}_{\\hspace{-.55em} \\lng^{'}} \\hspace\{.1em}}",
            molo: "{{\\mm_{\\hspace{-.1em}O}}_{\\hspace{-.1em}\\llo}\\hspace{.1em}}",

            prgm: "{\\mathcal{P}}",
            intr: "{\\mathcal{I}}",
            cmp: "{\\mathcal{C}}",
            prgmcmp: "{\\mathcal{Pc}}",

            sx: "{\\mathop{\\rm Sx}\\nolimits}",
            dx: "{\\mathop{\\rm Dx}\\nolimits}",
            caret: "{\\;\\hat{}\\;}",
            HALT: "{\\mathit{HALT}}",

            // Backus-Naur form
            bnf: [
                `{\\mathopen\\langle\\hspace{.1em}
                    \\text{#1}
                 \\hspace{.1em}\\mathclose\\rangle}`,
                1
            ],
            Coloneqq: "{\\;\\mathop{::=}\\;}",

            // Over/Under/Over-Under ==>
            Oimplies: ["{\\overset{\\substack{#1}}{\\implies}}", 1],
            Uimplies: ["{\\underset{\\substack{#1}}{\\implies}}", 1],
            OUimplies: [
                "{\\overset{\\substack{#1}}{\\underset{\\substack{#2}}{\\implies}}}",
                2
            ],



            // subimplies: ["{\\underset{\\substack{(#1)}}{\\implies}}", 1],
            // supimplies: ["{\\overset{\\substack{#1}}{\\implies}}", 1],
            // supsubimplies: ["{\\overset{\\substack{#1}}{\\underset{\\substack{#2}}{\\implies}} }", 2],
            astimplies: "{\\overset{\\substack{\\ast}}{\\implies}}",
            deff: "{\\overset{\\substack{\\hspace{-0.1em}\\text{def}}}{\\iff}}",

            // absolute value since it's not defined
            abs: ["{\\mathopen\\lvert #1\\mathclose\\rvert}", 1],

            XiV: "{X \\cap V}",
            XuV: "{X \\cup V}",
            XuVplus: "{{(X \\cup V)}^+}",
            XuVast: "{{(X \\cup V)}^\\ast}",
            grammar: "{G = \\set{X,\\ V,\\ S,\\ P}}",
            supto: ["{\\overset{\\substack{#1}}{\\to}}", 1],
            sup: ["{\\overset{\\substack{#2}}{#1}}", 2]
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

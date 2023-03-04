window.MathJax = {
    loader: {
        load: ['[tex]/textmacros', '[tex]/cancel'],
    },
    tex: {
        inlineMath: [["\\(", "\\)"]],
        displayMath: [["\\[", "\\]"]],
        processEscapes: true,
        processEnvironments: true,
        packages: {
            '[+]': ['textmacros', 'cancel']
        },
        macros: {
            // numerical sets
            N: "{\\mathbb{N}}",
            Z: "{\\mathbb{Z}}",
            Q: "{\\mathbb{Q}}",
            R: "{\\mathbb{R}}",
            I: "{\\mathbb{I}}",
            C: "{\\mathbb{C}}",

            // math operators
            mcd: "{\\operatorname{mcd}}",
            dom: "{\\operatorname{dom}}",
            codom: "{\\operatorname{codom}}",

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
            sup: ["{\\overset{\\substack{#2}}{#1}}", 2],

            ceil: ["{\\mathopen\\lceil #1 \\mathclose\\rceil}", 1],
            floor: ["{\\mathopen\\lfloor #1 \\mathclose\\rfloor}", 1],

            // units of measurement
            bit: "{\\small\\rm\\, b}",
            byte: "{\\small\\rm\\, B}",

            bbit: "{\\small\\rm\\, bit}",
            bbyte: "{\\small\\rm\\, byte}",

            KB: "{\\small\\rm\\, KB}",
            MB: "{\\small\\rm\\, MB}",
            GB: "{\\small\\rm\\, GB}",
            TB: "{\\small\\rm\\, TB}",
            PB: "{\\small\\rm\\, PB}",
            EB: "{\\small\\rm\\, EB}",
            ZB: "{\\small\\rm\\, ZB}",
            YB: "{\\small\\rm\\, YB}",

            KiB: "{\\small\\rm\\, KiB}",
            MiB: "{\\small\\rm\\, MiB}",
            GiB: "{\\small\\rm\\, GiB}",
            TiB: "{\\small\\rm\\, TiB}",
            PiB: "{\\small\\rm\\, PiB}",
            EiB: "{\\small\\rm\\, EiB}",
            ZiB: "{\\small\\rm\\, ZiB}",
            YiB: "{\\small\\rm\\, YiB}",

            // typeset binary/hexadecimal numbers
            bin: ["{0{\\small\\text{b}}\\hspace{0.07em} #1}", 1],
            hex: ["{0\\text{x}\\hspace{0.07em} \\mathrm{#1}}", 1],

            // some QoL macros
            ifrac: ["{^{#1} \\!/ _{\\!#2}}", 2],
            oneton: ["{#2_1,\\, #2_2, \\,\\dotsc,\\, #2_{#1}}", 2, "n" ],
            sumton: ["{#2_1 + #2_2 +\\dotsb+ #2_{#1}}", 2, "n" ],

            // logical operators
            lxor: "\\veebar",

            // (reverse) polish notation NOT GOOD!! complicates things
            prefx: ["{\\mathbin{#1}\\, #2#3}", 3],
            postx: ["{#2#3 \\,\\mathbin{#1}\\;}", 3],
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

package org.hightail;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URL;
import org.hightail.parsers.contest.*;
import org.hightail.parsers.task.*;
import org.hightail.util.XTrustProvider;
import org.htmlparser.util.ParserException;

public enum SupportedSites {
    CodeForces  (
            "codeforces",
            new CodeForcesTaskParser(),
            new CodeForcesContestParser()),
    CodeChef    (
            "codechef",
            new CodeChefTaskParser(),
            new CodeChefContestParser()),
    Jutge       (
            "jutge",
            new JutgeTaskParser(),
            new JutgeContestParser())
    ;
    
    private TaskParser taskParser;
    private ContestParser contestParser;
    private String defaultDirectory;
    
    private SupportedSites(String defaultDirectory, TaskParser taskParser, ContestParser contestParser) {
        this.defaultDirectory = defaultDirectory;
        this.taskParser = taskParser;
        this.contestParser = contestParser;
    }
    
    public String getDirectory() {
        return Config.get(toString() + "Directory", defaultDirectory);
    }
    
    private static void verifyURL(String url) throws ParserException {
        try {
            if (url.contains("jutge.")) {
                // workaround to cope with the SSL cerificate problem on Jutge
                // this is needed also for the task parser itself to work (this method gets called before the task parser)
                XTrustProvider.install();
            }
            URL u = new URL(url);
            HttpURLConnection conn = (HttpURLConnection) u.openConnection();
            conn.setRequestMethod("GET");
            conn.connect();
            int code = conn.getResponseCode();
            if (code != 200) {
                throw new ParserException("Incorrect URL.");
            }
        } catch (IOException ex) {
            throw new ParserException("Malformed URL.");
        }
    }
    
    public static SupportedSites getSite(String URL) {
        for (SupportedSites site : values()) {
            if (site.taskParser.isCorrectURL(URL) || site.contestParser.isCorrectURL(URL)) {
                return site;
            }
        }
        return null;
    }
    
    public static TaskParser getTaskParser(String URL) throws ParserException {
        verifyURL(URL);
        SupportedSites site = getSite(URL);
        if (site == null) {
            throw new ParserException("Incorrect url or this site is currently unsupported.");
        }
        return site.taskParser;
    }
    
    public static ContestParser getContestParser(String URL) throws ParserException {
        verifyURL(URL);
        SupportedSites site = getSite(URL);
        if (site == null) {
            throw new ParserException("Incorrect url or this site is currently unsupported.");
        }
        return site.contestParser;
    }
}

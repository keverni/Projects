using System;
using OpenQA.Selenium;
using OpenQA.Selenium.Chrome;
using OpenQA.Selenium.Chrome.ChromeDriverExtensions;
using System.Threading;
using System.Drawing;

internal class Program
{
    static void Agroserver(IWebDriver driver, string SeedRequest, string RegionRequest)
    {
        try
        {
            driver.Navigate().GoToUrl("https://agroserver.ru/zerno/");
        }
        catch (Exception ex)
        {
            Console.WriteLine("Server connections is out! Please wait and try again!");
            return;
        }
        for (int i = 1; i < 18; ++i)
        {
        try
        {
                
                string XPath = "/html/body/div[2]/div/div[5]/div[4]/div[1]/div[" + i + "]/a";
                IWebElement TypeOfSeed = driver.FindElement(By.XPath(XPath));

                if (SeedRequest == TypeOfSeed.Text)
                {
                    TypeOfSeed.Click();
                    break;
                }
                else
                {
                    continue;
                }
        } catch (Exception ex) 
        {
                Console.WriteLine("Server connections is out! Please wait and try again!");
                return;
        }


        }
        IWebElement RegionList = driver.FindElement(By.XPath("/html/body/div[2]/div/div[5]/div[6]/form/div/div[1]/div[2]/div/a"));
        RegionList.Click();
        Thread.Sleep(1000);

        int quatityOfProduct = 0;
        var ChooseRegion = driver.FindElements(By.TagName("li"));
        for (int i = 0; i < ChooseRegion.Count; ++i)
        {
        var SplitRegion = ChooseRegion[i].Text.Split(new[] { '(' });   
        if (SplitRegion[0].ToLower() == RegionRequest.ToLower())
        {    
            ChooseRegion[i].Click();
            var Submit = driver.FindElement(By.ClassName("query_win_button_submit"));
            Submit.Click();

                quatityOfProduct = Int32.Parse(SplitRegion[1].Remove(SplitRegion[1].Length - 1, 1));
                break;

        }
        else{ continue; }

        }
        Thread.Sleep(1500);
        int CountOfProduct = 1;
        for (int indexOfProduct = 1; indexOfProduct <= quatityOfProduct; ++indexOfProduct)
        {
            
            if (CountOfProduct == 50)
            {
                string XPathNextPage = "/html/body/div[2]/div/div[5]/div[7]/ul[1]/li[3]/a";
                IWebElement NextPage = driver.FindElement(By.XPath(XPathNextPage));
                NextPage.Click();
                CountOfProduct = 1;
            }
            else
            {
                string XPathProductName = $"/html/body/div[2]/div/div[5]/div[7]/div[1]/div/div[{CountOfProduct}]/div/div[1]/div[2]/a";
                string XPathProductPrice = $"/html/body/div[2]/div/div[5]/div[7]/div[1]/div/div[{CountOfProduct}]/div/div[1]/div[3]/div[1]/div";
                try
                {
                    IWebElement ProductName = driver.FindElement(By.XPath(XPathProductName));
                    Console.WriteLine($"Product Name: {ProductName.Text}");
                    Console.WriteLine($"Product URL: {ProductName.GetAttribute("href")}");

                }catch (Exception ex) { break; }
                
                try
                {
                    
                    IWebElement ProductPrice = driver.FindElement(By.XPath(XPathProductPrice));
                    Console.WriteLine($"Product Price: {ProductPrice.Text}");
                }catch (Exception ex) 
                {
                    ++CountOfProduct;
                    continue; 
                }
                
                


            }

            ++CountOfProduct;
        }
    }
    
    static void ZolRU(IWebDriver driver, string SeedRequest, string RegionRequest)
    {
        driver.Navigate().GoToUrl("https://doska.zol.ru/");
        
        for (int i = 2; i < 16; ++i)
        {

            Thread.Sleep(500);
            string XPathTypeSeed = $"/html/body/table[5]/tbody/tr/td/table/tbody/tr/td[1]/table/tbody/tr[{i}]/td[1]/li/a";
            string XPathTypeSeed2 = $"/html/body/table[5]/tbody/tr/td/table/tbody/tr/td[1]/table/tbody/tr[{i}]/td[2]/li/a";
            
            IWebElement TypeOfSeed = driver.FindElement(By.XPath(XPathTypeSeed));
            IWebElement TypeOfSeed2 = driver.FindElement(By.XPath(XPathTypeSeed2));
            if (TypeOfSeed.Text.ToLower() == SeedRequest.ToLower())
            {
                TypeOfSeed.Click();
            } else if (TypeOfSeed2.Text.ToLower() == SeedRequest.ToLower())
            {
                TypeOfSeed2.Click();
            }
        }
        Thread.Sleep(800);
        IWebElement Mark = driver.FindElement(By.XPath("//*[@id=\"nearby_countries\"]"));
        Mark.Click();
        Mark = driver.FindElement(By.XPath("//*[@id=\"buy\"]"));
        Mark.Click();
        Mark = driver.FindElement(By.XPath("//*[@id=\"sell_other\"]"));
        Mark.Click();
        Mark = driver.FindElement(By.XPath("//*[@id=\"buy_other\"]"));
        Mark.Click();
        Mark = driver.FindElement(By.XPath("//*[@id=\"other\"]"));
        Mark.Click();
        var RegionList = driver.FindElements(By.TagName("option"));
        for (int i = 0; i < RegionList.Count; ++i)
        {
            string ReadyRegion = RegionList[i].Text;
            if (RegionList[i].Text.Contains(" и "))
            {
                ReadyRegion = RegionList[i].Text.Split(new string[] { " и " }, StringSplitOptions.RemoveEmptyEntries)[1];
                
            }
            if (ReadyRegion.ToLower() == RegionRequest.ToLower())
            {
                RegionList[i].Click();
                IWebElement Sumbit = driver.FindElement(By.XPath("/html/body/form/table/tbody/tr[1]/td[4]/input"));
                Sumbit.Click();
                Thread.Sleep(1000);
                IWebElement MarkRegion = driver.FindElement(By.XPath("//*[@id=\"nearby_regions\"]"));
                MarkRegion.Click();
                break;
            }
        }
        Thread.Sleep(2000);
        string[] ListOfProduct = { };
        IWebDriver driverProduct = new ChromeDriver();
        for (int indexProduct = 4; indexProduct < 424; ++indexProduct)
        {
           try
           {
                IWebElement Product = driver.FindElement(By.XPath($"/html/body/div[17]/table/tbody/tr[{indexProduct}]/td[2]/table/tbody/tr/td[3]/b/a"));
                Console.WriteLine($"Product Name: {Product.GetAttribute("title")}");
                Console.WriteLine($"Product URL: {Product.GetAttribute("href")}");
                driverProduct.Navigate().GoToUrl(Product.GetAttribute("href"));
                IWebElement Price = driverProduct.FindElement(By.XPath($"/html/body/div[3]/div[2]/div[1]/div[6]/div[1]/div[2]/div/span"));
                Console.WriteLine($"Product Price: {Price.Text}");
                
            }
            catch { continue; }
        }
        driverProduct.Close();
        
        
    }

    // TODO: Вытянуть ссылки на товары
    static void Avito(IWebDriver driver, string SeedRequest, string RegionRequest)

    {
        driver.Navigate().GoToUrl("https://www.avito.ru/");
        try
        {
            Thread.Sleep(2500);
            IWebElement RegionChoose = driver.FindElement(By.XPath("/html/body/div[1]/div/div[4]/div/div[1]/div/div[4]/div[1]/div/span/span/span/span/span"));
            RegionChoose.Click();
            // Ввод региона
            Thread.Sleep(1000);
            RegionChoose = driver.FindElement(By.ClassName("styles-module-root-fLlcQ"));
            RegionChoose.Click();
            RegionChoose = driver.FindElement(By.ClassName("styles-module-searchInput-XEbi7")); // /html/body/div[2]/div[38]/div/div[2]/div/div/div/div/div[1]/div[1]/div/div[1]/div
            RegionChoose.SendKeys(RegionRequest);
            Thread.Sleep(2000);
            RegionChoose = driver.FindElement(By.ClassName("styles-module-item-oEdtv"));
            RegionChoose.Click();
            // Кнопка показать 

            RegionChoose = driver.FindElement(By.ClassName("styles-module-root_preset_primary-n8Trp"));
            RegionChoose.Click();
        }
        catch { Avito(driver, SeedRequest, RegionRequest); }

        Thread.Sleep(2000);
        IWebElement SearchOfProduct = driver.FindElement(By.ClassName("input-input-Zpzc1"));
        SearchOfProduct.SendKeys(SeedRequest);
        SearchOfProduct = driver.FindElement(By.ClassName("desktop-15w37ob"));
        SearchOfProduct.Click();

        var AllProduct = driver.FindElements(By.ClassName("styles-module-root-TWVKW"));
        for (int i = 1; i < AllProduct.Count; ++i)
        {
            try
            {
                IWebElement Product = driver.FindElement(By.XPath($"/html/body/div[1]/div/div[4]/div/div[2]/div[3]/div[3]/div[3]/div[2]/div[{i}]/div/div/div[2]/div[2]/div/a/h3"));
                Console.WriteLine($"Product Name: {Product.Text}");
                IWebElement Price = driver.FindElement(By.XPath($"/html/body/div[1]/div/div[4]/div/div[2]/div[3]/div[3]/div[3]/div[2]/div[{i}]/div/div/div[2]/div[3]/span/div/p/strong/span"));
                Console.WriteLine($"Product Price: {Price.Text}");
            } catch { continue; }
        }
    }

    static void TelegramCtats(string SeedRequest, string RegionRequest)
    {
        // 
    }
    
    // Кукуруза - Воронежская область
    static void Main()
    {

        
        
        IWebDriver driver;
        
        Random randomInt = new Random();
        int RandomNum = randomInt.Next(0, 3);
        Console.WriteLine(RandomNum);
        if (RandomNum == 2)
        {
            
            
            ChromeOptions options = new ChromeOptions();
            options.AddHttpProxy("185.162.233.234", 8000, "SCBEq8", "QV6XWw");
            driver = new ChromeDriver(options);
            
        }
        else{ driver = new ChromeDriver(); }
        driver.Manage().Window.Size = new Size(1920, 1080);
        string SeedRequest = "";
        string RegionRequest = "";
        string Request;
        string[] SplitRequest;
        while (true) 
        {
            Request = Console.ReadLine();
            SplitRequest = Request.Split(new[] { '-' });
            if (SplitRequest.Length != 2)
            {
                Console.WriteLine("Invalid request.");
                continue;
            }
            else
            {
                SeedRequest = SplitRequest[0].Remove(SplitRequest[0].Length - 1, 1);
                RegionRequest = SplitRequest[1].Remove(0, 1);
                break;

            }
        }
        Console.WriteLine("Agroserver.ru");
        Agroserver(driver, SeedRequest, RegionRequest);
        //Thread.Sleep(5000);
        Console.WriteLine("Zol.ru");
        ZolRU(driver, SeedRequest, RegionRequest);
        
        Console.WriteLine("Avito.ru");
        Avito(driver, SeedRequest, RegionRequest);

        // driver.Close();

    }
}
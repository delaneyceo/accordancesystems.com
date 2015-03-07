<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['branding']: Items for the branding region.
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see omega_preprocess_page()
 */
?>
<?php print $messages; ?>
<div class="main section">
    <div class="container">
        <header>
            <div class="branding">
                <img src="<?php print $base_path . 'sites/all/themes/accordancesystems/images/temp_splash_images/as_logo.png'; ?>" class="logo" alt ="Accordance Systems logo"/>
                <h1 class="site-name">Accordance Systems</h1>
            </div>

            <div class="contact-info">
                <a href="tel:5152234845" class="phone">
                    <span class="label">
                        Phone:
                    </span>
                    <span class="phone-number">
                        515-223-4845
                    </span>
                </a>
                <a href="mailto:sales@accordancesystems.com" class="email">
                    <span class="label">
                        Email:
                    </span>
                    <span class="email-address">
                        sales@accordancesystems.com
                    </span>
                </a>
            </div>
        </header>

        <div class="product-plug">
            <img src="<?php print $base_path . 'sites/all/themes/accordancesystems/images/temp_splash_images/araid_product.png'; ?>" alt ="araid 5000-GP"/>
            <div class="product-description">
                <span class="line-1">
                    <strong>Never</strong> lose data from
                </span>
                <span class="line-2">
                    a hard disk crash <strong>again</strong>.
                </span>
                <div class="action-links">
                    <a href="tel:5152234845" class="btn">Call Us</a>
                    <a href="mailto:sales@accordancesystems.com" class="btn">Email Us</a>
                </div>
            </div>
        </div>
    </div>
</div>

<div class="coming-soon section">
    <div class="container">
        <p>To serve you better... we are in the process of developing a new website.</p>
        <img src="<?php print $base_path . 'sites/all/themes/accordancesystems/images/temp_splash_images/web_soon.png'; ?>" alt ="Website coming soon"/>
    </div>
</div>

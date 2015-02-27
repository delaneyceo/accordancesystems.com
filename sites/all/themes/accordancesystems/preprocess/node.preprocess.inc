<?php
include_once drupal_get_path('module', 'ctools') . "/includes/cleanstring.inc";

/**
 * Implements hook_preprocess_node().
 */
function accordancesystems_preprocess_node(&$variables) {
  $variables['print_node_anchor'] = TRUE;

  switch ($variables['type']) {
    case 'dealer':
      if ($variables['elements']['#view_mode'] == 'dealer_listing') {
        $variables['print_node_anchor'] = FALSE;
        // Change the url title to be consistent.
        if (!empty($variables['content']['field_dealer_url'])) {
          $variables['content']['field_dealer_url'][0]['#element']['title'] = 'Visit website';
        }
      }
      break;
    case 'araid_controller_display':
      if ($variables['elements']['#view_mode'] == 'featured_slide') {
        $variables['print_node_anchor'] = FALSE;
      }
      if ($variables['elements']['#view_mode'] == 'product_controller_tabs') {
        $i = 0;

        // Gather field based items.
        if (!empty($variables['content']['field_controller_features_ref'])) {
          $variables['product_controller_links'][$i]['title'] = '<i class="fa fa-tasks"></i> Overview';
          $variables['product_controller_links'][$i]['type'] = 'tab';
          $variables['product_controller_links'][$i]['tab_content'] = render($variables['content']['field_controller_features_ref']);
          $i = $i + 1;
        }
        if (!empty($variables['content']['field_controller_photo'])) {
          $variables['product_controller_links'][$i]['title'] = '<i class="fa fa-picture-o"></i> Photos';
          $variables['product_controller_links'][$i]['type'] = 'tab';
          $variables['product_controller_links'][$i]['tab_content_needs_container'] = TRUE;
          $variables['product_controller_links'][$i]['tab_content'] = render($variables['content']['field_controller_photo']);
          $i = $i + 1;
        }
        if (!empty($variables['content']['field_controller_manual']) || !empty($variables['content']['field_controller_firmware'])) {
          $variables['product_controller_links'][$i]['title'] = '<i class="fa fa-download"></i> Download Center';
          $variables['product_controller_links'][$i]['type'] = 'tab';
          $variables['product_controller_links'][$i]['tab_content_needs_container'] = TRUE;
          $variables['product_controller_links'][$i]['tab_content'] = render($variables['content']['field_controller_manual']);
          $variables['product_controller_links'][$i]['tab_content'] = $variables['product_controller_links'][$i]['tab_content'] . render($variables['content']['field_controller_firmware']);
          $i = $i + 1;
        }

        // Gather views items.
        $has_browser_compatibility = views_get_view_result('browser_compatibility', 'browser_compatibility_by_controller_nid', $variables['node']->nid);
        if (!empty($has_browser_compatibility)) {
          $variables['product_controller_links'][$i]['title'] = '<i class="fa fa-hdd-o"></i> Compatibility';
          $variables['product_controller_links'][$i]['type'] = 'tab';
          $variables['product_controller_links'][$i]['tab_content_needs_container'] = TRUE;
          $variables['product_controller_links'][$i]['tab_content'] = views_embed_view('browser_compatibility', 'browser_compatibility_by_controller_nid', $variables['node']->nid);;
          $i = $i + 1;
         }

        // Example external link item.
        // $variables['product_controller_links'][$i]['title'] = 'Testimonials';
        // $variables['product_controller_links'][$i]['type'] = 'link';
        // $variables['product_controller_links'][$i]['url'] = 'http://google.com';
        // $i = $i + 1;

        foreach ($variables['product_controller_links'] as $delta => &$item) {
          $clean_name = ctools_cleanstring($item['title'], array('lower case'=>TRUE));

          // Add default attributes.
          $item['attributes']['list_attributes']['class'][] = 'list-item';
          $item['attributes']['content_attributes']['class'][] = 'tab-content';

          // Add classes if this is the first tab item.
          if ($delta == 0) {
            $item['attributes']['list_attributes']['class'][] = 'active';
            $item['attributes']['content_attributes']['class'][] = 'active';
          }

          // Add config for tab items.
          if ($item['type'] == 'tab') {
            // Add li attributes.
            $item['attributes']['list_attributes']['role'] = 'presentation';
            // Add anchor attributes.
            $item['attributes']['anchor_attributes']['href'] = '#' . $clean_name;
            $item['attributes']['anchor_attributes']['aria-controls'] = $clean_name;
            $item['attributes']['anchor_attributes']['role'] = 'tab';
            $item['attributes']['anchor_attributes']['data-toggle'] = 'tab';
            // Add content attributes.
            $item['attributes']['content_attributes']['role'] = 'tabpanel';
            $item['attributes']['content_attributes']['class'][] = 'tab-pane';
            $item['attributes']['content_attributes']['id'] = $clean_name;
            // Add container wrapper if needed.
            if (isset($item['tab_content_needs_container'])) {
              $item['attributes']['content_attributes']['class'][] = 'l-container';
              $item['attributes']['anchor_attributes']['class'][] = 'dropline';
            }
          }

          // Add config for link items.
          if ($item['type'] == 'link') {
            $item['attributes']['anchor_attributes']['href'] = $item['url'];
            $item['tab_content'] = NULL;
          }

          // Render attributes
          $item['attributes']['rendered_li'] = drupal_attributes($item['attributes']['list_attributes']);
          $item['attributes']['rendered_a'] = drupal_attributes($item['attributes']['anchor_attributes']);
          $item['attributes']['rendered_content'] = drupal_attributes($item['attributes']['content_attributes']);
        }
      }
      break;
  }
}

